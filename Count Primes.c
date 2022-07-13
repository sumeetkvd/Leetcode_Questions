Count Primes: -


The solution in C: -


int countPrimes(int num)
{
        int loop_var;
        bool *array;
        int prime = 0;
        long long temp;
        if(num  <= 2 )
                return 0;
        array = malloc(sizeof(bool)*num);
        while(loop_var < num){
                array[loop_var] = 0;
                loop_var++;
        }
        loop_var = 2;
        for(loop_var = 2; loop_var < num; loop_var++){
                if(array[loop_var])
                        continue;
                temp = (long)loop_var*(long)loop_var;
                prime++;
                while(temp < num){
                        array[temp] = 1;
                        temp  += loop_var;
                }
        }
        return prime;
}



