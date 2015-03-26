/* 27. Remove Element
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

 // two pointers
class Solution {
public:
    int removeElement(int a[], int n, int elem) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != elem) {
                a[count++] = a[i];
            }
        }
        return count;
    }
};