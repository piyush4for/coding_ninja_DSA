//making array as CBT
#include<vector>
using namespace std;

class maxPriorityQueue{
    vector<int> pq;

    public:

    maxPriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()) return 0;     //prioirty queue is empty
        return pq[pq.size()-1];
    }

    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size() - 1 ;
        
        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] > pq[parentIndex]){
                swap(pq[childIndex],pq[parentIndex]);
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }  
    }

    int removeMax(){
        if(isEmpty()) return 0;

        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        //now satisfying heap order property i.e, down heapify

        int parentIndex = 0; 
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex +2;

        while(((parentIndex*2) +1) < pq.size()){
            int maxIndex = parentIndex;
            if(pq[maxIndex] < pq[leftChildIndex]){
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex]){
                maxIndex = rightChildIndex;
            }
            if(maxIndex == parentIndex) break;

            swap(pq[maxIndex],pq[parentIndex]);

            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex +2;
        }
        return ans;
    }    

};