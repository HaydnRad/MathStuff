#include<iostream>
#include<string>
using namespace std;
 
void bop(unsigned long long int &n){ //Very creative and relavent function name
	if ((n & 1) == 0) //Is the last bit a 0? I.e. a multiple of 2
		 n >>= 1; //Divide by 2 via bitshift
	else
		n += (n << 1) + 1; //Add 2*n + 1 (effectively 3n+1)
};

int main(){
	unsigned long long int N; //'unsigned long long int' is probably *way* overkill, but hey at least it wont overflow anytime soon
	cin >> N; //Starting number
	unsigned long long int m = N; //Maximum number found
        unsigned int l = 0; //Path length
	while (N != 1){
		bop(N);
		m = max(m, N); 
		l++; 
	}
	cout << "Largest number: " << m << endl
	<< "Steps taken: " << l << endl;	
}
