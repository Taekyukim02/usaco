#include <iostream>

using namespace std;

int main() {
    int answer = 0;

    // First part of the problem
    for(int N=1; N <= 100; N++) {
        for(int a=1; a <= N-5; a++) {
            if(a > 6*(N-50))
                break;
            for(int b=a+1; b <= N-4; b++) {
                if(a + b > 6*(N-50))
                    break;
                for(int c=b+1; c <= N-3; c++) {
                    if(a + b + c > 6*(N-50))
                        break;
                    for(int d=c+1; d <= N-2; d++) {
                        if(a + b + c + d> 6*(N-50))
                            break;
                        for(int e=d+1; e <= N-1; e++) {
                            if(a + b + c + d + e > 6*(N-50))
                                break;
                            for(int f=e+1; f <= N; f++) {
                                if(a+b+c+d+e+f == 6*(N-50))
                                answer ++;
                            }
                        }
                    }
                }
            }
        }
    }

    // Second part of the problem
    int N = 100;
    for(int a=1; a <= N-5; a++) {
        if(a > 6*50.5)
            break;
        for(int b=a+1; b <= N-4; b++) {
            if(a + b > 6*50.5)
                break;
            for(int c=b+1; c <= N-3; c++) {
                if(a + b + c > 6*50.5)
                    break;
                for(int d=c+1; d <= N-2; d++) {
                    if(a + b + c + d> 6*50.5)
                        break;
                    for(int e=d+1; e <= N-1; e++) {
                        if(a + b + c + d + e > 6*50.5)
                            break;
                        for(int f=e+1; f <= N; f++) {
                            if(a+b+c+d+e+f == 6*50.5)
                                answer ++;
                        }
                    }
                }
            }
        }
    }


    // Output answer
    cout << answer << endl;
}