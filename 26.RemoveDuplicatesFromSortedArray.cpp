/*
26. Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*/

int removeDuplicates(int A[], int n)
{
    if (n == 0)
        return 0;

    int start=0;
    int preElem = A[0];
    for (int i = 0; i < n; i++)
    {
        if (preElem == A[i])
            continue;
        // else
        A[++start] = A[i];
        preElem = A[i];
    }
    return start+1;
}

void testCase_RemoveDuplicates()
{
    int a[10] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5};
    int b[2] = {1, 1};
    int c[3] = {1, 1, 2};
    int d[] = {};
    cout<<removeDuplicates(a, 10)<<endl;
    cout<<removeDuplicates(b, 2)<<endl;
    cout<<removeDuplicates(c, 3)<<endl;
    cout<<removeDuplicates(d, 0)<<endl;
}
