//
// Created by Vamsi Lingamallu on 17/03/18.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int T;
    cin >>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        double  d = double(n) / double(n+1);
        printf("%.8lf\n",d);
    }
    return 0;
}