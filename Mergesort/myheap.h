template <typename T>
class Heap {
public:
    explicit Heap() {
        n = 0;
    }
    
    T min(int &value) const {
        value = num[0];
        return a[0];
    }
    
    void extractMin() {
        n--;
        if (n > 0){ 
            swap(a[0], a[n]);
            swap(num[0], num[n]);
            siftDown(0);
        }
    }
    
    void push(R value, int q){
        n++;
        a[n - 1] = value;
        num[n-1] = q;
        siftUp(n - 1); 
    }
    
    ~Heap() {}
    
private:

    T a[1000];//elements
    int num[1000];//file numbers
    int n;
    int parent (int value) const {
        return (value - 1) / 2;
    }
    
    int leftSon (int value) const {
        return 2 * value + 1;
    }

    int rightSon (int value) const {
        return 2 * value + 2;
    }

    void siftDown (int value) {
        int z = value;
        if ( rightSon(value) < n ){
            if ((a[value] > a[leftSon(value)] ) || (a[value] > a[rightSon(value)])) {
                if ((a[value] > a[leftSon(value)]) && (a[rightSon(value)] >= a[leftSon(value)])) {
                    swap(a[value], a[leftSon(value)]);
                    swap(num[value], num[leftSon(value)]);
                    value = leftSon(value) ;
                }
            else
                if ((a[value] > a[rightSon(value)]) && (a[rightSon(value)] <= a[leftSon(value)])){
                    swap(a[value], a[rightSon(value)]);
                    swap(num[value], num[rightSon(value)]);
                    value = rightSon(value);
                }
            }
        }
        else {
            if (leftSon(value) < n)
                if(a[value] > a[leftSon(value)]){
                    swap(a[value], a[leftSon(value)]);
                    swap(num[value], num[leftSon(value)]);
                    value = leftSon(value);
                }
         
        }
        if (z < value)
            siftDown(value);
    }

    void siftUp(int value) {
        while ((value > 0) && (a[value] < a[parent(value)])) {
            swap(a[value], a[parent(value)]); 
            swap(num[value], num[parent(value)]); 
            value = parent(value);
        }
    }
}





