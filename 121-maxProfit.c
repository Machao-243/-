#define Max_NUM 1000000

int maxProfit(int* prices, int pricesSize) {
    int minPrice = Max_NUM;
    int maxProfit = 0;
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }else if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}