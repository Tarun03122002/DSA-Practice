    for(int i=0;i<length;i++){
        int elementAsIndex = abs(nums[i]);
        if(nums[elementAsIndex]<0){
            return elementAsIndex;
        }
        nums[elementAsIndex]*=-1;
    }
    return -1;