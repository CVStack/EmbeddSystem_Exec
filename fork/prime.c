int checkprime(int num){
    if(num<=1) return 0;

    for(int i=2;i<=num>>1;i++){
        if(num%i==0) return 0;
    }
    return 1;
}