#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm5
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    //for (size_t i = data_.size()/2; i > 0; --i)
    for (size_t i = data_.size()/2; i > 0; --i)
    {
      SiftDown(i);
    }
    
    




    /*
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
    */
  }
  void SiftDown(int i){
    int MinIndex = i;
    int l = LeftChild(i);
    if (l <= data_.size() && data_[l-1] < data_[MinIndex-1])
      MinIndex = l;
    int r = RightChild(i);
    if(r <= data_.size() && data_[r-1] < data_[MinIndex-1])
      MinIndex = r;
    if (MinIndex != i){
      swap(data_[MinIndex-1],data_[i-1]);
      swaps_.push_back(make_pair(i-1, MinIndex-1));
      SiftDown(MinIndex);
    }
 
  }

  int LeftChild(int i){
    return (2*i);
  }

  int RightChild(int i){
    return (2*i)+1;
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
