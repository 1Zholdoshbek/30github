class ProductOfNumbers {
public:
    vector<long long> prod;
    int lastZero = -1;

    ProductOfNumbers() {
        prod.push_back(1); 
    }

    void add(int num) {
        if (num == 0) {
            prod.push_back(1);
            lastZero = prod.size() - 1; 
        } else {
            prod.push_back(prod.back() * num);
        }
    }

    int getProduct(int k) {
        int sz = prod.size();
        if (k > sz - 1) return 0; 
        if (lastZero >= sz - k) {
            return 0; 
        }
        return prod[sz - 1] / prod[sz - 1 - k];
    }
};

