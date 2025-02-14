class ProductOfNumbers {
private:
    vector<int> prefix;
    int lastZeroIndex;

public:
    ProductOfNumbers() {
        prefix = {1};
        lastZeroIndex = -1;
    }
    
    void add(int num) {
        if (num == 0) {
            prefix = {1}; 
            lastZeroIndex = prefix.size();
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) return 0;  
        
        return prefix[n - 1] / prefix[n - k - 1];
    }
};
