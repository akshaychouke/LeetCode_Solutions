/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    let ansArray = [];
    let indx = 0;

    while(indx < arr.length){
        ansArray.push(arr.slice(indx,indx+size));
        indx += size;
    }

    return ansArray;
};