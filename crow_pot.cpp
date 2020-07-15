#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

int minCrowPotStoneSecond(int *overflow_numbers){
    int total_stones=0;

    for(int i=n-1; i>0; i--){
        overflow_numbers[i] = max(0,overflow_numbers[i]-overflow_numbers[i-1]);
        cout<<overflow_numbers[i]<<endl;
    }

    for(int i=0; i<k; i++){
        total_stones+=(overflow_numbers[i]*(n-i));
    }
    return total_stones;
}

int main(){
	cin >> n;
	int *arr = new int[n + 1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin >> k;

    sort(arr,arr+n);

	cout << minCrowPotStoneSecond(arr);
	return 0;
}
