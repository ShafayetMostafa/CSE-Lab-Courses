///04324205101011

let balance = 10000;

function atm() {
    let choice;
    do {
        choice = prompt(
            "Welcome to the ATM Machine!\n" +
            "1. Check Balance\n" +
            "2. Deposit Money\n" +
            "3. Withdraw Money\n" +
            "4. Exit\n" +
            "Enter your choice (1-4):"
        );

        switch (choice) {
            case "1":
                alert(`Your balance is: $${balance}`);
                break;
            case "2":
                let deposit = parseFloat(prompt("Enter amount to deposit:"));
                if (!isNaN(deposit) && deposit > 0) {
                    balance += deposit;
                    alert(`Deposited $${deposit}. New balance: $${balance}`);
                } else {
                    alert("Invalid deposit amount.");
                }
                break;
            case "3":
                let withdraw = parseFloat(prompt("Enter amount to withdraw:"));
                if (!isNaN(withdraw) && withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    alert(`Withdrew $${withdraw}. New balance: $${balance}`);
                } else {
                    alert("Invalid or insufficient funds.");
                }
                break;
            case "4":
                alert("Thank you. Goodbye!");
                break;
            default:
                alert("Invalid choice. Please enter 1-4.");
        }
    } while (choice !== "4");
}

atm();
function groupAnagrams(words) {
    const map = new Map();

    for (let word of words) {
        // Sort letters of the word to get the key
        const key = word.split('').sort().join('');
        if (!map.has(key)) {
            map.set(key, []);
        }
        map.get(key).push(word);
    }

    return Array.from(map.values());
}
