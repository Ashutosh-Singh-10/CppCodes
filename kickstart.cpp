// // #include <iostream>
// // #include <string>
// // using namespace std;
// // int is_palindrome(string str)
// // {
// //     for (int i = 0; i < sizeof(str) - 4; i++)
// //     {
// //         if (str[i] == str[i + 4] && str[i + 1] == str[i + 3])
// //         {
        
// //             return 0;
// //         }
// //     }

// //     return 1;
// // }
// // int ans(string str, int index)

// // {
// //     if (index >= sizeof(str))
// //     {
// //         cout<<is_palindrome(str);
// //         return is_palindrome(str);
// //     }
// //     for (int i = index; i < sizeof(str); i++)
// //     {
// //         if (str[i] == '?')
// //         {
// //             str.replace(i, 1, "0");
// //             if (ans(str,i)==1)
// //             {
// //                 cout<<"hey"<<endl;
// //                 return 1;
// //             }
// //             else
// //             {
// //                 str.replace(i, 1, "1");
// //                 if (ans(str,i)==1)
// //                 {
// //                     return 1;
// //                 }
// //                 else
// //                     return 0;
// //             }
// //         }
// //     }
// // }
// // int main()
// // {
// //     int num;
// //     cin >> num;
// //     string given;
// //     while (num--)
// //     {
// //         cin>>given;
// //         if (ans(given, 0))
// //         {
// //             cout << "POSSIBLE";
// //         }
// //         else
// //         {
// //             cout << "IMPOSSIBLE";
// //         }
// //     }

// //     return 0;
// // }
// #include <iostream>
// using namespace std;

// int main()
// {
//     cout<<10**5<<endl;
//    int test;
//    cin>>test;
//    int a,b,temp;
//    int count=0;
//    int product,sum;
//    while(test--)
//    {
//        cin>>a;
//        cin>>b;
       
       
//        for(int i=a;i<=b;i++)
//         {
//             product=1;
//             sum=0;
//             temp=i;
//             while(temp!=0)
//             {
//                 sum+=temp%10;
//                 product*=temp%10;
//                 temp=temp/10;
                
//             }
            
//             if (sum!=0)
//             {
//                 if(product%sum==0)
//                 {
//                     count++;
//                 }
//             }
//         }
//         cout<<count<<endl;
//    }
// }
#include <iostream>
#include <cmath>
using namespace std;
int sizess(int num)
{
    int count=0;
    while(num!=0)
    {
        count++;
        num=num/10;
    }
    return count;
    
}
int digit_to_add(int num)
{
    int sum=0;
    while(num!=0)
    {
        sum+=num%10;
        num/=10;
    }
    return 9-sum;
}
int main()
{
    int quan=10;
    long long test;
    cin>>test;
    long long given;
    int size;
    int index;
    int digit;
    while(test--)
    {
        cin>>given;
        
        size=sizess(given);
        
        index=size;
        index--;
        digit=digit_to_add(given);
        if(digit==0)
        {
            index--;
        }
        while(index)
        {
            if(   (given%int(pow(10,index+1)))/int(pow(10,index)) >digit )
            break;
            index--;
        }
        if(quan==0)
        cout<<endl;
        else 
        quan=0;
        cout<<given%int(pow(10,index+1))<<digit<<given%int(pow(10,index))<<endl;
        
        
    }
    return 0;
}
    

    