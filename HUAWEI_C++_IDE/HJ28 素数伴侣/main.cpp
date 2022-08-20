
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPrime(int m) {
	if (m <= 1) return false;
	for (int i = 2; i < sqrt(m); i++) {
		if (m % i == 0) return false;
	}
	return true;
}

//建立N长质数check表 欧拉线性质数筛
void buildPrimeTable(int N, bool* isprime_t, int *prime_t,int &count) {
	int cnt=0;
	isprime_t[0] = isprime_t[1] = false;
	for (int i = 2; i < N; i++) {
		if (isprime_t[i]) prime_t[cnt++] = i;//如果是质数就加入到质数表中，用最小的质数的i倍提前标记了后面的质数
		for (int j = 0; j< N; j++) {
			if (i * prime_t[j] >= N) break;
			isprime_t[i * prime_t[j]] = false;//每一个素数都将其当前的i倍数标记为非素数
			if (i % prime_t[j] == 0) break;//最关键只标记一次，不会重复标j记一个数是不是素数的倍数
		}
		
	}
	count = cnt;
}

void buildisPrimeTable(int N, bool* isprime_t) {
	int cnt = 0;
	int* prime_t = new int[N];
	isprime_t[0] = isprime_t[1] = false;
	for (int i = 2; i < N; i++) {
		if (isprime_t[i]) prime_t[cnt++] = i;//如果是质数就加入到质数表中，用最小的质数的i倍提前标记了后面的质数
		for (int j = 0; j < N; j++) {
			if (i * prime_t[j] >= N) break;
			isprime_t[i * prime_t[j]] = false;//每一个素数都将其当前的i倍数标记为非素数
			if (i % prime_t[j] == 0) break;//最关键只标记一次，不会重复标j记一个数是不是素数的倍数
		}
	}
	delete []prime_t;
}

bool odd_find_enev_matchbest(int odd, vector<int> &evens, vector<bool> &even_used, vector<int> &even_match, bool *isprime_t) {
	//遍历每一个偶数与奇数匹配
	for (int i = 0; i < evens.size(); i++) {
		if (!even_used[i] && isprime_t[odd + evens[i]]) {
			even_used[i] = true;//这个偶数被使用
			//如果第i个偶数还未配对，或者跟它配对的奇数有别的选择
			if (even_match[i] == 0 || odd_find_enev_matchbest(even_match[i], evens, even_used, even_match, isprime_t)) {
				even_match[i] = odd;
				return true;
			}
		}
	}
	return false;
}




int main() {
	const int len = 60000;
	bool isprime_t[len];
	memset(isprime_t, true, sizeof(isprime_t));
	buildisPrimeTable(len, isprime_t);
	int N,tmp;
 	while (cin >> N) {
		vector<int> nums(N);
		vector<int> odds;//奇数组
		vector<int> evens;//偶数组
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			nums[i] = tmp;
			if (tmp % 2 == 0) evens.push_back(tmp);
			else odds.push_back(tmp);
		}
		//素数一定是由一个奇数和一个偶数的和构成
		int count = 0;
		if (odds.size() == 0 || evens.size() == 0) {
			cout << count << endl;
			continue;
		}
		vector<int> even_match(evens.size(), 0);//记录每一个偶数[i]匹配的是哪一个奇数even_match[i]
		for (int i = 0; i < odds.size(); i++) {//遍历每一个奇数
			vector<bool> even_used(evens.size(), false);//偶数没有被使用则标记值为0
			//对每一个奇数，能找到最优的与之配对的偶数，那么匹配+1
			if (odd_find_enev_matchbest(odds[i],evens,even_used,even_match,isprime_t)) {
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}