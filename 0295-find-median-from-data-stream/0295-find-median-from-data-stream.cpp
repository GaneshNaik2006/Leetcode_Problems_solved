class MedianFinder {
public:
priority_queue<double> l;
priority_queue<double,vector<double> ,greater<double>> r;
    MedianFinder() {
        
    }
    
  
          void addNum(int num) {
      l.push(num);

      r.push(l.top());
      l.pop();

      if(r.size()>l.size()){
        l.push(r.top());
        r.pop();
      }
       
     }
    
    
    double findMedian() {
        if(l.size()>r.size()) return l.top();
        else if (l.size()== r.size()) return (l.top()+r.top())/2.0;

        return -1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */