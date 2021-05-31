#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}
float wallis_pi(int n) {
	float num,den,temp,pi=0;
	

    for (int i=1; i<n;i++){
    	num= 4*pow(i,2);
    	den=4*pow(i,2)- 1;
    	temp=num/den;
    	
    	if(i==1){
    	    pi=temp;
    	}
    	else{
    	    pi=temp*pi;
    	    }
     	}
    pi=pi*2;
    return pi;
}

