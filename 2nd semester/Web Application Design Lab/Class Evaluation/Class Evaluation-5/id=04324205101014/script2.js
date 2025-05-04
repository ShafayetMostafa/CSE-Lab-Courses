///04324205101011

function findAnagrams(words) {
    const map = new Map();
  
    for (const word of words) {
      // Sort the characters of the word to create a key
      const sorted = word.split('').sort().join('');
      
      // Group words by their sorted character key
      if (map.has(sorted)) {
        map.get(sorted).push(word);
      } else {
        map.set(sorted, [word]);
      }
    }
  
    // Only return groups that contain more than one word (true anagram groups)
    const result = [];
    for (const group of map.values()) {
      if (group.length > 1) {
        result.push(group);
      }
    }
  
    return result;
  }
  
  // Example usage:
  const input = ["listen", "silent", "heart", "earth", "dog", "god"];
  const output = findAnagrams(input);
  console.log(output);
  