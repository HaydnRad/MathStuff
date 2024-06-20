#include<unordered_set> //Might as well squeeze the time complexity as much as possible
#include<iostream>
#include<string>
using namespace std;

void bop(unsigned long long int &n){ //Very creative and relavent function name
	if ((n & 1) == 0) //Is the last bit a 0? I.e. a multiple of 2
		 n >>= 1; //Divide by 2 via bitshift
	else
		n += (n << 1) + 1; //Add 2*n + 1 (effectively 3n+1)
};

unsigned long long int findNewPeak(unsigned long long int n, unordered_set<unsigned long long int> &checked){ //Finds the highest number from a seed thats not already been seen by another
	unsigned long long int highest = n;
	while (checked.insert(n).second){
		bop(n);
		highest = max(highest, n);
	}
	return highest;
};

int main(){
	int num; //Hmm not unsigned...
	cin >> num; //The number of peaks the function should find
	unsigned long long int peak = 1, tempPeak = 1, seed = 1;
	unordered_set<unsigned long long int> checked = {1};
	while (num != 0){ //I hope you know about ctrl+c if you use a negative number :)
		tempPeak = findNewPeak(seed, checked);
		if (tempPeak > peak){
			peak = tempPeak;
			cout << seed << " : " << peak << endl;
			num--;
		}
		seed += 2; //Skips even numbers
	}
}
