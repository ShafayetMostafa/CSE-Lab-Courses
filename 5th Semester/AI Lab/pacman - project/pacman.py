import curses
import random
import time
import heapq
from collections import deque

# Map symbols
WALL = '#'
EMPTY = ' '
PELLET = '*'          # Changed from '.' to '*' as requested!
POWER_PELLET = 'O'

# Pac-Man directional sprites (animates between open mouth and chomp)
PACMAN_SPRITES = {
    (-1, 0): ('^', 'A'),   # Moving UP
    (1, 0):  ('v', 'V'),   # Moving DOWN
    (0, -1): ('<', 'D'),   # Moving LEFT
    (0, 1):  ('>', 'C'),   # Moving RIGHT
}

# Ghost definitions with distinct retro sprites and colors
GHOST_DEFS = [
    {"name": "Blinky", "sprite": "M", "color_pair": 2},  # Fiery Red
    {"name": "Pinky",  "sprite": "W", "color_pair": 3},  # Neon Pink / Magenta
    {"name": "Inky",   "sprite": "&", "color_pair": 4},  # Electric Cyan
    {"name": "Clyde",  "sprite": "@", "color_pair": 5},  # Warm Orange / Yellow
    {"name": "Shadow", "sprite": "$", "color_pair": 6},  # Emerald Green
    {"name": "Spooky", "sprite": "%", "color_pair": 7},  # Ghostly White
]

# Arrow key mappings
DIRS = {
    curses.KEY_UP: (-1, 0),
    curses.KEY_DOWN: (1, 0),
    curses.KEY_LEFT: (0, -1),
    curses.KEY_RIGHT: (0, 1),
}

# Difficulty levels (Adjusted so ghosts move at a comfortable, manageable pace)
DIFFICULTY_SETTINGS = {
    "Easy":   {"ghost_speed": 0.50, "ghost_count": 2, "chase_radius": 6},
    "Medium": {"ghost_speed": 0.35, "ghost_count": 4, "chase_radius": 11},
    "Hard":   {"ghost_speed": 0.22, "ghost_count": 6, "chase_radius": 20},
}

def init_all_colors():
    curses.start_color()
    try:
        curses.use_default_colors()
    except Exception:
        pass
    # 1: Pac-Man (Bright Arcade Yellow)
    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    # 2: Ghost 1 - Blinky (Red)
    curses.init_pair(2, curses.COLOR_RED, curses.COLOR_BLACK)
    # 3: Ghost 2 - Pinky (Magenta)
    curses.init_pair(3, curses.COLOR_MAGENTA, curses.COLOR_BLACK)
    # 4: Ghost 3 - Inky (Cyan)
    curses.init_pair(4, curses.COLOR_CYAN, curses.COLOR_BLACK)
    # 5: Ghost 4 - Clyde (Yellow/Orange)
    curses.init_pair(5, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    # 6: Ghost 5 - Shadow (Green)
    curses.init_pair(6, curses.COLOR_GREEN, curses.COLOR_BLACK)
    # 7: Ghost 6 - Spooky (White)
    curses.init_pair(7, curses.COLOR_WHITE, curses.COLOR_BLACK)
    # 8: Classic Arcade Neon Blue Walls (Matching the uploaded image!)
    curses.init_pair(8, curses.COLOR_BLUE, curses.COLOR_BLACK)
    # 9: Pellets (Golden Yellow '*')
    curses.init_pair(9, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    # 10: Selected Menu Item (Black on Gold/Yellow)
    curses.init_pair(10, curses.COLOR_BLACK, curses.COLOR_YELLOW)
    # 11: HUD & Headers (Warm Amber/Yellow)
    curses.init_pair(11, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    # 12: Pop-up Dialog Body (Crisp White on Charcoal Black)
    curses.init_pair(12, curses.COLOR_WHITE, curses.COLOR_BLACK)
    # 13: Pop-up Dialog Border & Highlights (Cyan/Gold on Black)
    curses.init_pair(13, curses.COLOR_CYAN, curses.COLOR_BLACK)
    # 14: Accent Highlight (Bright Yellow on Black)
    curses.init_pair(14, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    # 15: Warning / Lives Red
    curses.init_pair(15, curses.COLOR_RED, curses.COLOR_BLACK)


class Game:
    def __init__(self, stdscr, difficulty="Medium"):
        self.stdscr = stdscr
        self.difficulty = difficulty
        self.map = []
        self.pacman_pos = (1, 1)
        self.pacman_dir = (0, 1)
        self.chomp_frame = 0
        self.ghosts = []
        self.score = 0
        self.total_pellets = 0
        self.lives = 3            # 3 Lives!
        self.paused = False
        
        cfg = DIFFICULTY_SETTINGS[self.difficulty]
        self.ghost_speed = cfg["ghost_speed"]
        self.ghost_count = cfg["ghost_count"]
        self.chase_radius = cfg["chase_radius"]
        self.last_ghost_move = time.time()
        
        # Single-press movement throttle (Prevents holding key from speeding)
        self.last_player_move = 0
        self.player_move_delay = 0.12  # Seconds between moves (1 press = 1 move)
        
        self.load_classic_arcade_maze()
        self.place_entities()

    def load_classic_arcade_maze(self):
        """Loads the big classic arcade Pac-Man labyrinth with center Ghost House,

        side escape avenues, symmetrical T-bars, and '*' pellets.
        """
        raw_layout = [
            "#######################################################",
            "#O*************************#*************************O#",
            "#*#########*#############*###*#############*#########*#",
            "#*#########*#############*###*#############*#########*#",
            "#*#########*#############*###*#############*#########*#",
            "#*****************************************************#",
            "#*#########*#####*###################*#####*#########*#",
            "#*#########*#####*#########*#########*#####*#########*#",
            "#*#########*#####*#########*#########*#####*#########*#",
            "#***********#####*#########*#########*#####***********#",
            "###########*#####*#########*#########*#####*###########",
            "###########*#####*                   *#####*###########",
            "###########*#####*  #################*#####*###########",
            "           *     *  ******************     *           ",
            "###########*#####*  #################*#####*###########",
            "###########*#####*                   *#####*###########",
            "###########*#####*  #################*#####*###########",
            "#***********#####*  #################*#####***********#",
            "#*#########*#####*  #################*#####*#########*#",
            "#*#########*#####*###################*#####*#########*#",
            "#*#########*#####*###################*#####*#########*#",
            "#*****************************************************#",
            "#*#########*#############*###*#############*#########*#",
            "#*#########*#############*###*#############*#########*#",
            "#*#########*#############*###*#############*#########*#",
            "#O*************************#*************************O#",
            "#######################################################"
        ]
        
        # Cleanly load the maze directly from raw_layout (no rogue pellets in ghost house)
        self.map = [list(row) for row in raw_layout]
        self.maze_rows = len(self.map)
        self.maze_cols = len(self.map[0])
        
        # Pac-Man starting cell is clear
        self.map[1][1] = EMPTY
        
        # Calculate pellets to eat
        self.total_pellets = sum(row.count(PELLET) + row.count(POWER_PELLET) for row in self.map)

    def place_entities(self):
        """Initial placement or respawn after losing a life."""
        self.pacman_pos = (1, 1)
        self.pacman_dir = (0, 1)
        self.ghosts = []
        
        # Central Ghost House spawn coordinates
        ghost_spawns = [
            (13, 25), (13, 27), (13, 29), (12, 27), (11, 27), (15, 27)
        ]
        for i in range(self.ghost_count):
            spawn = ghost_spawns[i % len(ghost_spawns)]
            g_def = GHOST_DEFS[i % len(GHOST_DEFS)]
            self.ghosts.append({
                "pos": list(spawn),
                "def": g_def
            })

    def draw(self):
        self.stdscr.clear()
        h, w = self.stdscr.getmaxyx()
        
        # Position HUD at the top row, and place maze underneath
        hud_y = 0
        offset_y = max(1, (h - self.maze_rows) // 2)
        if offset_y == 0:
            offset_y = 1
        offset_x = max(1, (w - self.maze_cols) // 2)

        # Build Lives Display
        lives_icons = " ".join(["(C)" for _ in range(self.lives)])

        # Top HUD (Warm Golden Amber with Lives Indicator)
        hud = f" PAC-MAN  |  SCORE: {self.score:05d}  |  LIVES: {lives_icons}  |  DIFF: {self.difficulty.upper()}  |  PELLETS: {max(0, self.total_pellets):03d} "
        try:
            self.stdscr.addstr(hud_y, max(0, (w - len(hud)) // 2), hud, curses.color_pair(11) | curses.A_BOLD)
        except curses.error:
            pass

        # Draw Labyrinth Walls, '*' Pellets, Pac-Man, and Ghosts
        for y, row in enumerate(self.map):
            for x, ch in enumerate(row):
                scr_y, scr_x = offset_y + y, offset_x + x
                if scr_y >= h - 1 or scr_x >= w - 1:
                    continue
                
                # Draw Pac-Man with animated directional mouth
                if (y, x) == self.pacman_pos:
                    sprite_pair = PACMAN_SPRITES.get(self.pacman_dir, ('>', 'C'))
                    pac_char = sprite_pair[self.chomp_frame % 2]
                    self.stdscr.addch(scr_y, scr_x, pac_char, curses.color_pair(1) | curses.A_BOLD)
                    continue
                
                # Draw Ghosts
                ghost_on_cell = None
                for g in self.ghosts:
                    if g["pos"][0] == y and g["pos"][1] == x:
                        ghost_on_cell = g
                        break
                
                if ghost_on_cell:
                    color = curses.color_pair(ghost_on_cell["def"]["color_pair"]) | curses.A_BOLD
                    self.stdscr.addch(scr_y, scr_x, ghost_on_cell["def"]["sprite"], color)
                elif ch == WALL:
                    # Electric Neon Blue Walls (Matching reference image)
                    self.stdscr.addch(scr_y, scr_x, '#', curses.color_pair(8) | curses.A_BOLD)
                elif ch == PELLET:
                    # Golden '*' Pellets
                    self.stdscr.addch(scr_y, scr_x, '*', curses.color_pair(9) | curses.A_BOLD)
                elif ch == POWER_PELLET:
                    # Glowing power pellet
                    self.stdscr.addch(scr_y, scr_x, 'O', curses.color_pair(1) | curses.A_BOLD)
                else:
                    self.stdscr.addch(scr_y, scr_x, ' ')

        # Bottom Controls Line
        controls = " [ARROWS] Move   [ESC] Pause   [Q] Quit to Menu "
        try:
            self.stdscr.addstr(offset_y + self.maze_rows + 1, max(0, (w - len(controls)) // 2), controls, curses.color_pair(7) | curses.A_DIM)
        except curses.error:
            pass

        if self.paused:
            self.draw_popup(" GAME PAUSED ", [
                "The game is paused.",
                "",
                "Press [ESC] to resume playing",
                "Press [Q] to quit to main menu"
            ])

        self.stdscr.refresh()

    def draw_popup(self, title, lines):
        """Draws an elegant dark dialog box with cyan/gold border and clear highlights."""
        h, w = self.stdscr.getmaxyx()
        box_w = max(len(title) + 8, max(len(l) for l in lines) + 6, 52)
        box_h = len(lines) + 4
        sy = max(0, (h - box_h) // 2)
        sx = max(0, (w - box_w) // 2)
        
        # Clear dialog background
        for y in range(box_h):
            if sy + y < h - 1:
                self.stdscr.addstr(sy + y, sx, " " * box_w, curses.color_pair(12))
            
        # Draw borders
        top_border = "+" + "=" * (box_w - 2) + "+"
        bot_border = "+" + "=" * (box_w - 2) + "+"
        if sy < h - 1:
            self.stdscr.addstr(sy, sx, top_border, curses.color_pair(13) | curses.A_BOLD)
        if sy + box_h - 1 < h - 1:
            self.stdscr.addstr(sy + box_h - 1, sx, bot_border, curses.color_pair(13) | curses.A_BOLD)
            
        for y in range(1, box_h - 1):
            if sy + y < h - 1:
                self.stdscr.addch(sy + y, sx, "|", curses.color_pair(13) | curses.A_BOLD)
                self.stdscr.addch(sy + y, sx + box_w - 1, "|", curses.color_pair(13) | curses.A_BOLD)
            
        # Title
        t_x = sx + (box_w - len(title)) // 2
        if sy < h - 1:
            self.stdscr.addstr(sy, t_x, f" {title} ", curses.color_pair(14) | curses.A_BOLD)
        
        # Content
        for i, line in enumerate(lines):
            lx = sx + (box_w - len(line)) // 2
            if sy + 2 + i < h - 1:
                if ">>" in line or "[" in line:
                    self.stdscr.addstr(sy + 2 + i, lx, line, curses.color_pair(14) | curses.A_BOLD)
                elif "Remaining Lives" in line or "CAUGHT" in line:
                    self.stdscr.addstr(sy + 2 + i, lx, line, curses.color_pair(15) | curses.A_BOLD)
                else:
                    self.stdscr.addstr(sy + 2 + i, lx, line, curses.color_pair(12))

    def move_pacman(self, direction):
        dy, dx = DIRS[direction]
        self.pacman_dir = (dy, dx)
        self.chomp_frame += 1
        ny, nx = self.pacman_pos[0] + dy, self.pacman_pos[1] + dx
        
        # Wrap-around tunnels on left & right borders
        if nx < 0:
            nx = self.maze_cols - 1
        elif nx >= self.maze_cols:
            nx = 0
            
        # Boundary & Wall check
        if 0 <= ny < self.maze_rows and 0 <= nx < self.maze_cols:
            if self.map[ny][nx] != WALL:
                self.pacman_pos = (ny, nx)
                if self.map[ny][nx] == PELLET:
                    self.map[ny][nx] = EMPTY
                    self.score += 10
                    self.total_pellets -= 1
                elif self.map[ny][nx] == POWER_PELLET:
                    self.map[ny][nx] = EMPTY
                    self.score += 50
                    self.total_pellets -= 1

    # ---------------------------------------------------------------------
    # Classical AI: A* Search Algorithm with Manhattan Heuristic
    # ---------------------------------------------------------------------
    def a_star(self, start, goal):
        open_set = []
        heapq.heappush(open_set, (0, start))
        came_from = {}
        g_score = {start: 0}
        f_score = {start: self.manhattan(start, goal)}
        
        while open_set:
            _, current = heapq.heappop(open_set)
            if current == goal:
                path = []
                while current != start:
                    path.append(current)
                    current = came_from[current]
                path.reverse()
                return path[0] if path else start
            
            for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ny = current[0] + dy
                nx = current[1] + dx
                
                # Wrap-around tunnels on left & right borders
                if nx < 0:
                    nx = self.maze_cols - 1
                elif nx >= self.maze_cols:
                    nx = 0
                    
                if 0 <= ny < self.maze_rows and 0 <= nx < self.maze_cols:
                    if self.map[ny][nx] == WALL:
                        continue
                    neighbor = (ny, nx)
                    tentative_g = g_score[current] + 1
                    if tentative_g < g_score.get(neighbor, float('inf')):
                        came_from[neighbor] = current
                        g_score[neighbor] = tentative_g
                        f_score[neighbor] = tentative_g + self.manhattan(neighbor, goal)
                        heapq.heappush(open_set, (f_score[neighbor], neighbor))
                        
        # Fallback: if goal is obstructed or unreached, step in the best open legal direction towards goal
        best_step = start
        min_dist = float('inf')
        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ny = start[0] + dy
            nx = start[1] + dx
            if nx < 0: nx = self.maze_cols - 1
            elif nx >= self.maze_cols: nx = 0
            if 0 <= ny < self.maze_rows and 0 <= nx < self.maze_cols:
                if self.map[ny][nx] != WALL:
                    d = self.manhattan((ny, nx), goal)
                    if d < min_dist:
                        min_dist = d
                        best_step = (ny, nx)
        return best_step

    def manhattan(self, a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])

    def move_ghosts(self):
        """Active Classical AI: Ghosts continuously relocate and pursue Pac-Man across the entire maze."""
        for idx, g in enumerate(self.ghosts):
            gy, gx = g["pos"]
            ghost_start = (gy, gx)
            
            # Classical Arcade AI Personalities:
            # - Blinky (Red) & Inky (Cyan): Direct persistent stalkers - always track Pac-Man directly!
            # - Pinky (Pink): Ambush interceptor - predicts Pac-Man's trajectory 3 steps ahead
            # - Clyde & Others: Hunts Pac-Man when far, retreats to corners when very close
            if idx in (0, 2):
                target = self.pacman_pos
            elif idx == 1:
                p_dy, p_dx = self.pacman_dir
                ty = min(max(1, self.pacman_pos[0] + p_dy * 3), self.maze_rows - 2)
                tx = min(max(1, self.pacman_pos[1] + p_dx * 3), self.maze_cols - 2)
                target = (ty, tx) if self.map[ty][tx] != WALL else self.pacman_pos
            else:
                dist = self.manhattan(ghost_start, self.pacman_pos)
                if dist > 6:
                    target = self.pacman_pos
                else:
                    target = (self.maze_rows - 2, 1)  # Corner patrol
                    
            next_step = self.a_star(ghost_start, target)
            g["pos"][0], g["pos"][1] = next_step

    def check_collision(self):
        for g in self.ghosts:
            if g["pos"][0] == self.pacman_pos[0] and g["pos"][1] == self.pacman_pos[1]:
                return True
        return False

    def handle_lost_life(self):
        """Called when a ghost catches Pac-Man. Reduces lives by 1."""
        self.lives -= 1
        if self.lives > 0:
            self.draw()
            self.stdscr.nodelay(False)
            self.draw_popup(" OUCH! CAUGHT BY A GHOST! ", [
                "You were caught by a ghost patrolling the corridors!",
                "",
                f"Remaining Lives: {self.lives} / 3",
                "",
                "Pac-Man and ghosts are returning to starting positions.",
                "Your score and collected pellets are saved!",
                "",
                ">> Press ANY KEY to Continue Playing <<"
            ])
            self.stdscr.refresh()
            self.stdscr.getch()
            self.stdscr.nodelay(True)
            
            # Reset positions but keep score & maze state
            self.place_entities()
            self.last_ghost_move = time.time()
            return False  # Game continues!
        else:
            # All 3 lives lost!
            self.draw()
            return self.game_over_dialog("GAME OVER! You lost all 3 lives!", False)

    def show_controls_popup(self):
        """Pop-up displayed right after clicking Play."""
        self.stdscr.nodelay(False)
        self.draw()
        self.draw_popup("READY TO PLAY!", [
            "Navigate Pac-Man and clear the labyrinth '*' dots!",
            "",
            "Game Controls:",
            "  * [ARROW KEYS] : Move Pac-Man (^ v < >)",
            "  * [ESC]        : Pause / Resume game",
            "  * [Q]          : Quit back to main menu",
            "",
            f"You have 3 LIVES! If caught, you respawn safely.",
            "Ghost AI: Blinky(M) Pinky(W) Inky(&) Clyde(@)",
            "Ghosts hunt using A* Search & Manhattan Heuristics!",
            "",
            ">> Press [ENTER] or ANY KEY to Start <<"
        ])
        self.stdscr.refresh()
        self.stdscr.getch()
        self.stdscr.nodelay(True)

    def run(self):
        self.show_controls_popup()
        self.last_ghost_move = time.time()
        
        while True:
            if not self.paused:
                now = time.time()
                if now - self.last_ghost_move > self.ghost_speed:
                    self.move_ghosts()
                    self.last_ghost_move = now
                
                # Check ghost collisions with 3 lives system
                if self.check_collision():
                    result = self.handle_lost_life()
                    if result in ("QUIT", "MENU"):
                        return result
                
                # Check win condition
                remaining = sum(row.count(PELLET) + row.count(POWER_PELLET) for row in self.map)
                if self.total_pellets <= 0 or remaining == 0:
                    self.total_pellets = 0
                    self.draw()
                    result = self.game_over_dialog(f"VICTORY! You cleared all pellets! Score: {self.score}", True)
                    return result
                    
            self.draw()
            
            try:
                key = self.stdscr.getch()
            except Exception:
                key = -1
                
            if key == -1:
                time.sleep(0.02)
                continue
                
            if key == 27:  # ESC key
                self.paused = not self.paused
            elif key in (ord('q'), ord('Q')):
                break
            elif key in DIRS and not self.paused:
                now = time.time()
                # Enforce single-press move: prevents holding key from rocket-speeding
                if now - self.last_player_move >= self.player_move_delay:
                    self.move_pacman(key)
                    self.last_player_move = now
                    try:
                        curses.flushinp()  # Flush OS typematic auto-repeat backlog
                    except Exception:
                        pass

    def game_over_dialog(self, message, won):
        self.stdscr.nodelay(False)
        title = "CONGRATULATIONS!" if won else "GAME OVER"
        self.draw_popup(title, [
            message,
            "",
            f"Final Score: {self.score}",
            "",
            "Press [Q] to Quit the Game",
            "Press [ENTER] to Return to Main Menu"
        ])
        self.stdscr.refresh()
        while True:
            k = self.stdscr.getch()
            if k in (ord('q'), ord('Q')):
                return "QUIT"
            elif k in (10, 13, curses.KEY_ENTER, ord(' '), 27):
                return "MENU"


# -------------------------------------------------------------------------
# UI Screens: Instructions, Difficulty, and Main Menu
# -------------------------------------------------------------------------

def show_instructions_screen(stdscr):
    stdscr.nodelay(False)
    while True:
        stdscr.clear()
        h, w = stdscr.getmaxyx()
        
        title = " HOW TO PLAY PAC-MAN "
        stdscr.addstr(2, max(0, (w - len(title)) // 2), title, curses.color_pair(11) | curses.A_BOLD)
        
        lines = [
            ("GAMEPLAY OBJECTIVE:", curses.color_pair(14) | curses.A_BOLD),
            ("  Navigate Pac-Man through the classic maze and eat all stars (*).", curses.color_pair(12)),
            ("  Eat Power Pellets (O) for 50 bonus points!", curses.color_pair(12)),
            ("  You have 3 LIVES! Losing a life resets positions without losing score.", curses.color_pair(12)),
            ("", curses.color_pair(12)),
            ("CONTROLS:", curses.color_pair(14) | curses.A_BOLD),
            ("  * ARROW KEYS (UP / DOWN / LEFT / RIGHT) : Move Pac-Man", curses.color_pair(12)),
            ("  * ESC                                   : Pause / Resume game", curses.color_pair(12)),
            ("  * Q                                     : Quit to Main Menu", curses.color_pair(12)),
            ("", curses.color_pair(12)),
            (">> Press [ENTER] or [Q] to Return to Menu <<", curses.color_pair(10) | curses.A_BOLD)
        ]
        
        start_y = 4
        for i, (text, attr) in enumerate(lines):
            if start_y + i < h - 1:
                stdscr.addstr(start_y + i, max(2, (w - len(text)) // 2), text, attr)
                
        stdscr.refresh()
        key = stdscr.getch()
        if key in (10, 13, ord('q'), ord('Q'), 27):
            break

def change_difficulty_screen(stdscr, current_difficulty):
    stdscr.nodelay(False)
    options = ["Easy", "Medium", "Hard"]
    idx = options.index(current_difficulty) if current_difficulty in options else 1
    
    while True:
        stdscr.clear()
        h, w = stdscr.getmaxyx()
        
        title = " CHANGE GAME DIFFICULTY "
        stdscr.addstr(3, max(0, (w - len(title)) // 2), title, curses.color_pair(11) | curses.A_BOLD)
        
        sub = "Select difficulty using UP/DOWN arrows and press ENTER:"
        stdscr.addstr(5, max(0, (w - len(sub)) // 2), sub, curses.color_pair(12))
        
        desc = {
            "Easy":   "2 Ghosts  -  Slow & relaxed (0.50s)  -  Gentle pace",
            "Medium": "4 Ghosts  -  Moderate arcade (0.35s) -  Balanced pursuit",
            "Hard":   "6 Ghosts  -  Brisk pursuit (0.22s)   -  Tactical challenge"
        }
        
        for i, opt in enumerate(options):
            y = 8 + i * 3
            marker = "  [ SELECTED ]  " if i == idx else "                "
            label = f"  {i + 1}. {opt.upper():<7} {marker}"
            
            if i == idx:
                stdscr.addstr(y, max(2, (w - len(label)) // 2), label, curses.color_pair(10) | curses.A_BOLD)
                d_text = f"--> {desc[opt]}"
                stdscr.addstr(y + 1, max(2, (w - len(d_text)) // 2), d_text, curses.color_pair(14) | curses.A_BOLD)
            else:
                stdscr.addstr(y, max(2, (w - len(label)) // 2), label, curses.color_pair(12))
                d_text = f"    {desc[opt]}"
                stdscr.addstr(y + 1, max(2, (w - len(d_text)) // 2), d_text, curses.color_pair(7) | curses.A_DIM)
                
        footer = "Press [ENTER] to Confirm  |  [Q/ESC] to Cancel"
        stdscr.addstr(h - 3, max(0, (w - len(footer)) // 2), footer, curses.color_pair(7) | curses.A_DIM)
        
        stdscr.refresh()
        key = stdscr.getch()
        if key == curses.KEY_UP:
            idx = (idx - 1) % len(options)
        elif key == curses.KEY_DOWN:
            idx = (idx + 1) % len(options)
        elif key in (10, 13, curses.KEY_ENTER):
            return options[idx]
        elif key in (ord('q'), ord('Q'), 27):
            return current_difficulty

def main_menu(stdscr):
    curses.curs_set(0)
    stdscr.keypad(True)
    init_all_colors()
    
    current_difficulty = "Medium"
    menu_items = [
        "1. Play the game",
        "2. How to Play the game",
        "3. Change difficulty",
        "4. Quit"
    ]
    selected = 0
    
    # Retro Arcade ASCII Logo for PAC-MAN
    logo = [
        r"  _____         _____       __  __          _   _ ",
        r" |  __ \ /\    / ____|     |  \/  |   /\   | \ | |",
        r" | |__) /  \  | |   ______ | \  / |  /  \  |  \| |",
        r" |  ___/ /\ \ | |  |______|| |\/| | / /\ \ | . ` |",
        r" | |  / ____ \| |____      | |  | |/ ____ \| |\  |",
        r" |_| /_/    \_\\_____|     |_|  |_/_/    \_|_| \_|",
        r"              "
    ]
    
    while True:
        stdscr.nodelay(False)
        stdscr.clear()
        h, w = stdscr.getmaxyx()
        
        # Draw Logo
        logo_start_y = max(1, h // 2 - 12)
        for i, line in enumerate(logo):
            color = curses.color_pair(1) | curses.A_BOLD if i < len(logo) - 1 else curses.color_pair(13) | curses.A_BOLD
            stdscr.addstr(logo_start_y + i, max(0, (w - len(line)) // 2), line, color)
            
        # Current Settings Badge
        info = f"Current Difficulty: [{current_difficulty.upper()}]  |  Active Ghosts: {DIFFICULTY_SETTINGS[current_difficulty]['ghost_count']}  |  Lives: 3"
        stdscr.addstr(logo_start_y + len(logo) + 1, max(0, (w - len(info)) // 2), info, curses.color_pair(14) | curses.A_BOLD)
        
        # Menu Options
        menu_start_y = logo_start_y + len(logo) + 3
        for i, item in enumerate(menu_items):
            display_text = f"   {item}   "
            if i == 2:
                display_text = f"   {item} ({current_difficulty})   "
                
            x = max(0, (w - len(display_text)) // 2)
            y = menu_start_y + (i * 2)
            
            if i == selected:
                stdscr.addstr(y, x, f">> {display_text.strip()} <<", curses.color_pair(10) | curses.A_BOLD)
            else:
                stdscr.addstr(y, x, f"   {display_text.strip()}   ", curses.color_pair(12))
                
        # Footer
        footer = "Use [UP/DOWN] arrows to navigate  |  Press [ENTER] to select  |  [Q] to quit"
        stdscr.addstr(h - 2, max(0, (w - len(footer)) // 2), footer, curses.color_pair(7) | curses.A_DIM)
        
        stdscr.refresh()
        key = stdscr.getch()
        
        if key == curses.KEY_UP:
            selected = (selected - 1) % len(menu_items)
        elif key == curses.KEY_DOWN:
            selected = (selected + 1) % len(menu_items)
        elif key in (ord('1'), ord('2'), ord('3'), ord('4')):
            selected = key - ord('1')
            if selected == 0:
                game = Game(stdscr, difficulty=current_difficulty)
                res = game.run()
                if res == "QUIT":
                    break
            elif selected == 1:
                show_instructions_screen(stdscr)
            elif selected == 2:
                current_difficulty = change_difficulty_screen(stdscr, current_difficulty)
            elif selected == 3:
                break
        elif key in (10, 13, curses.KEY_ENTER):
            if selected == 0:
                game = Game(stdscr, difficulty=current_difficulty)
                res = game.run()
                if res == "QUIT":
                    break
            elif selected == 1:
                show_instructions_screen(stdscr)
            elif selected == 2:
                current_difficulty = change_difficulty_screen(stdscr, current_difficulty)
            elif selected == 3:
                break
        elif key in (ord('q'), ord('Q')):
            break

if __name__ == "__main__":
    curses.wrapper(main_menu)
