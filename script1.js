const Name = localStorage.getItem('Name');
const Amount = localStorage.getItem('Amount');
document.getElementById('names').textContent = Name;
document.getElementById('balance').textContent = Amount;

let amount = parseInt(Amount || "0");

const amt = document.getElementById("amt");
const No = document.getElementById("No");
let result = document.getElementById("result");
let win = document.getElementById("won");
let loos = document.getElementById("loos");

amt.addEventListener('input', () => {
    let enteredamt = parseInt(amt.value);
    if (enteredamt < 0) {
        alert("Please enter a positive number!");
        amt.value = "";
    } else if (enteredamt > amount) {
        alert("Please enter a bet amount within your deposit!");
        amt.value = "";
    }
});

No.addEventListener('input', () => {
    let enteredNo = parseInt(No.value);
    if ((enteredNo >= 1 && enteredNo <= 12) || No.value === "") {
    }
    else {
        alert("Invalid number! Please enter a number between 2 and 12.");
        No.value = "";
    }
});

const bet = () => {
    if (amt.value == "" || No.value == "") {
        alert("Enter the amount and the number you want to bet!");
    } else if (No.value == 1) {
        alert("Enter a valid bet number");
        No.value = "";
    } else {
        let diceNo = Math.floor(Math.random() * 11) + 2;
        let enteredNo = parseInt(No.value);
        let enteredamt = parseInt(amt.value);
        let won = (enteredNo === diceNo);
        let videocontainer = document.getElementById("dices");
        videocontainer.style.display = 'flex';

        setTimeout(() => {
            videocontainer.style.display = 'none';
            showResult(won, diceNo, enteredamt);
        }, 12000);
    }
}

const showResult = (won, diceNumber, betAmount) => {
    if (won) {
        Won();
        amount += betAmount * 10; // Multiply the bet amount by 10
    } else {
        Lose();
        amount -= betAmount; // Deduct the bet amount
    }

    localStorage.setItem('Amount', amount); // Update the amount in local storage
    document.getElementById('balance').textContent = amount; // Update balance in HTML
};

const Won = () => {
    result.style.display="flex";
    win.style.display="block";
}

const Lose =()=>{
    result.style.display="flex";
    loos.style.display="block";

}

const playAgain=()=>{
    result.style.display="none";
    win.style.display="none";
    loos.style.display="none";
    amt.value="";
    No.value="";
}

const home =()=>{
    localStorage.removeItem("Name");
    localStorage.removeItem("Amount");
    window.location.href='index.html';
    
}
