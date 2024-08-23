// Write a new JavaScript function called intBin(n) that will use the binary search algorithm to see if the square
// root of n is integer or otherwise. The function will take the integer n as input parameter and return true if the
// square root of n is integer, and false otherwise. The implementation of your function should have time complexity
// O(log n), so you need to avoid creating an array with n elements. 



const start = performance.now();

// function intBin(n){
//     for (i = 0; i < n*n; i++){
//         if (n == (i*i))
//             return true;
//     }
//     return false;
// }

// console.log(intBin(9));


// function binary(array, low, high, n){
//     while(low <= high){
//         pivot = low + Math.floor((high-low)/2);
        
//         if(n == array[pivot])
//             return true;

//         else if(n < array[pivot])
//             high = pivot - 1;
//         else if (n > array[pivot])
//             low = pivot + 1;
//     }
//     return false;    
// }

// var array=[0,1,2,3,4,5,6,7];
// var n = 8;
// console.log(binary(array, 0, array.length - 1, n));



// function binaryRecursion(low, high, n){
//     if(low > high)
//         return false;

//     pivot = low + Math.floor((high-low)/2);
    
//     if(n == pivot * pivot)
//         return true;

//     else if(n < pivot * pivot)
//         return binaryRecursion(low, pivot - 1, n);

//     else if (n > pivot * pivot)
//         return binaryRecursion(pivot + 1, high, n);
// }

// var result = binaryRecursion(0, 6, 7);
// console.log(result);


// function recSum(n){
//     if (n <= 0)
//         return n;
//     return n + recSum(n - 1);    
// }

// console.log(recSum(10));

// function recFactorial(n){
//     if (n <= 0)
//         return 1;
//     return n * recFactorial(n - 1);    
// }

// console.log(recFactorial(4));

// My solution:
var array = [];
var length = 10;
var index = 0;
for (var i = 0; i < length; i++){
    for(var j = 0; j < length; j++){
        for(var z = 0; z < length; z++){
            array[index++] = Math.floor(Math.random() * 10000000);
        }
    }
    
}



var list;
var temp;
for (var i = 0; i < array.length; i++){
    if(i == 0){
        list = new LLNode(array[i])
        temp = list;
        continue;
    }
    temp.next = new LLNode(array[i]);
    temp = temp.next;    
}

function LLNode(data) {
    this.data = data;
    this.next = null;
}

// Solution suggested by the book:
var head = new LLNode (5) ;
head . next = new LLNode (2) ;
head . next . next = new LLNode (1) ;



function searchLL(list, item){
    var temp = list;
    while(temp != null){
        if (temp.data == item)
            return true;
        temp = temp.next
    }
    return false;
}

// console.log(searchLL(list, 5));


function swapLL(point) {
    if ( point.next !== null ) {
        var store = point.data;
        point.data = point.next.data;
        point.next.data = store;
        return point;
    }
    return false;
}

function bubbleLL(head){
    var swapFlag;
    do{
        swapFlag = false;
        temp = head;
        while(temp.next !== null){
            if(temp.data > temp.next.data){
                swapFlag = true;
                swapLL(temp);
            }
            temp = temp.next;
        }
    } while(swapFlag);
}

function printLL(list){
    while(list != null){
        var char = String(list.data);
        process.stdout.write(char + ",");
        list = list.next;
    }
    console.log("");
}

// printLL(list);
process.stdout.write("unsorted list: ");
printLL(list);

process.stdout.write("sorted list: ");
bubbleLL(list);
printLL(list);

process.stdout.write("Unsorted head: ");
printLL(head);

process.stdout.write("sorted head: ");
bubbleLL(head);
printLL(head);

const end = performance.now();
console.log(`Runtime: ${(end - start)/1000} seconds`);