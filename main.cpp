#include<iostream>
using namespace std;

char tab[2000][2001]; 
int queue[4000000];

pair<int, int> conv(int num,int m) {
	return make_pair(num / m, num % m);
}
int conv2(int i, int j,int m) {
	return i * m + j;
}

int main() {
	int n;
	int m;
	if (scanf("%d %d ", &n, &m) != 2) { ; }
	for (int i = 0; i < n; i++) {
		if( (fgets(tab[i], m + 2, stdin)) == NULL ){ printf("Error"); }
	}
	int count_comp = 0;
	int start = 0;
	int end = 0;
	int i;
	int j ;
	for (int a = 0; a < n * m; a++) {
		i= conv(a, m).first;
		j = conv(a, m).second;
		if (tab[i][j]> 0){
			start = 0;
			end = 0;
			queue[0] = a;
			if (tab[i][j] != 'A') {
				while (start <= end) {
					int u = queue[start];
					i = conv(u, m).first;
					j = conv(u, m).second;
					if (tab[i][j] > 0) { tab[i][j] -= 128; }
					if (tab[i][j]+128 == 'B') {
						//the middle
						if ((i > 0 && i < n - 1 && j>0 && j < m - 1) || (i == 0 && j == m - 1) || (i==0 && j>0)) {
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j - 1] -= 128;

							}
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						//the corners
						else if (i == 0 && j == 0) {
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						else if (i == n - 1 && j == m - 1) {
							if((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//the bottom
						else if (i == n - 1) {
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//left
						else if (j == 0) {
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						//right
						else if (j == m - 1) {
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
					}
					else if (tab[i][j]+128 == 'C') {
						//the middle
						if (i > 0 && i < n - 1 && j>0 && j < m - 1) {
							if ((tab[i - 1][j] > 0) &&(tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//the corners
						else if (i == n - 1 && j == 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
						}
						else if (i == 0 && j == m - 1) {
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						else if (i == n - 1 && j == m - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0) &&(tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//upper
						else if (i == 0) {
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//the bottom
						else if (i == n - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F') ){
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//left
						else if (j == 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
						}
						//right
						else if (j == m - 1) {
							if ((tab[i - 1][j] > 0) &&(tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
					}
					else if (tab[i][j]+128 == 'D') {
						//the middle
						if (i > 0 && i < n - 1 && j>0 && j < m - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						//the corners
						else if (i == 0 && j == 0) {
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F') ){
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						else if (i == n - 1 && j == 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						else if (i == n - 1 && j == m - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}

						}
						//upper
						else if (i == 0) {

							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						//the bottom
						else if (i == n - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						//left
						else if (j == 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						//right
						else if (j == m - 1) {
							if ((tab[i - 1][j] > 0) &&(tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
						}
					}
					else if (tab[i][j]+128 == 'E') {
						//the middle
						if (i > 0 && i < n - 1 && j>0 && j < m - 1) {
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F') ){
									end++;
									queue[end] = conv2(i +1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						//the corners
						else if (i == 0 && j == 0) {
							if((tab[i][j + 1] > 0)&& (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						else if (i == n - 1 && j == 0) {
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						else if (i == 0 && j == m - 1) {

							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						//upper
						else if (i == 0) {
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
								//}
							}
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						//the bottom
						else if (i == n - 1) {
							if((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						//left
						else if (j == 0) {
							if ((tab[i][j + 1] > 0)&&(tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
							if ((tab[i + 1][j] > 0)&&(tab[i + 1][j] == 'C' || tab[i +1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
						//right
						else if (j == m - 1) {
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
						}
					}
					else if (tab[i][j]+128 == 'F') {
						//the middle
						if (i > 0 && i < n - 1 && j>0 && j < m - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i + 1][j] > 0) &&(tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//the corners
						else if (i == 0 && j == 0) {
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
						}
						else if (i == n - 1 && j == 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}

						}
						else if (i == 0 && j == m - 1) {
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						else if (i == n - 1 && j == m - 1) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//upper
						else if (i == 0) {
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}

							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//the bottom
						else if (i == n - 1) {

							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) && (tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}
							if ((tab[i][j - 1] > 0) && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
						//left
						else if (j == 0 && i - 1 >= 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i + 1][j] > 0) && (tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
							if ((tab[i][j + 1] > 0) &&(tab[i][j + 1] == 'B' || tab[i][j + 1] == 'C' || tab[i][j + 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j + 1, m);
									tab[i][j+1] -= 128;
							}

						}
						//right
						else if (j == m - 1 && i - 1 >= 0) {
							if ((tab[i - 1][j] > 0) && (tab[i - 1][j] == 'B' || tab[i - 1][j] == 'E' || tab[i - 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i - 1, j, m);
									tab[i-1][j] -= 128;
							}
							if ((tab[i + 1][j] > 0) &&(tab[i + 1][j] == 'C' || tab[i + 1][j] == 'D' || tab[i + 1][j] == 'F')) {
									end++;
									queue[end] = conv2(i + 1, j, m);
									tab[i+1][j] -= 128;
							}
							if ((tab[i][j - 1] > 0)&& j - 1 >= 0 && (tab[i][j - 1] == 'D' || tab[i][j - 1] == 'E' || tab[i][j - 1] == 'F')) {
									end++;
									queue[end] = conv2(i, j - 1, m);
									tab[i][j-1] -= 128;
							}
						}
					}
					start++;
				}
				count_comp++;
			}
		}
	}
	printf("%d",count_comp);
	return 0;
}