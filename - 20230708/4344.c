#include <stdio.h>

int main(){
	int c, n, over;
	int score[1000];
	double aver;

	scanf("%d", &c);

	for(int i = 0; i < c; i++){
		scanf("%d", &n);
		aver = 0.0;
        over = 0;
        
		for(int j = 0; j < n; j++){
			scanf("%d", &score[j]);
			aver += score[j];
		}
		aver /= n;
        for(int j = 0; j < n; j++){
			if(score[j] > aver){
                over ++;
            }
		}
        printf("%.3f%%\n", 100.0 * over / n);
	}
	return 0;
}