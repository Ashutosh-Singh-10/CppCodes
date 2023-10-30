#include <bits/stdc++.h>
using namespace std;
int _is_feasable(int arr[], int n, int target, int students)
{
    int temp = 0;

    for(int i=0;i<n;i++)
    {
        if((temp+arr[i])>target)
        {
            temp=arr[i];
            students--;
            if(!students) return 0;
        }
        else 
        {
            temp+=arr[i];
        }
    }   
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     // cout << "the students are" << students << endl;
    //     // temp += arr[i];
    //     // if (arr[i] > target)
    //     //     return 0;

    //     if (temp > target)
    //     {
    //         students--;

    //         if (!students)
    //         {
    //             return 0;
    //         }
    //         temp = 0;
    //     }
    // }
    // temp=0;
    // for(int i=1;i<=students;i++)
    // {
    //     if(arr[n-i]>target)
    //     return 0;

    // }
    return 1;
}

int page_allocation(int arr[], int n, int students)
{


    int min_books = arr[n-1];
    int max_books = 0;
    for (int i = 0; i < n; i++)
    {
        max_books += arr[i];
    }
    int mid_books;
    int ans = 0;

    while (1)
    {
        if (min_books > max_books)
        {
            return ans;
        }
        mid_books = (max_books + min_books) / 2;
        if (_is_feasable(arr, n, mid_books, students))
        {
            ans = mid_books;
            max_books = mid_books - 1;
        }
        else
        {
            min_books = mid_books + 1;
        }
        cout << mid_books << endl;
    }

    return 0;


}
int main()
{

    int arr[] = {12, 32, 44, 55, 60,64};
    int answer = page_allocation(arr, 6,4);
    cout << answer;

    return 0;
}