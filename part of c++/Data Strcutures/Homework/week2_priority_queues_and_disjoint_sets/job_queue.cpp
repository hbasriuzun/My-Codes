#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::cin;
using std::cout;
using std::swap;


class process{
  public:
  int workers;
  long long next_time;

  process(){
    workers = 0;
    next_time = std::numeric_limits<int>::max();
  }

};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
 
  vector<process> next_freee_time;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobsmy() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;

      if (i < num_workers_)
        next_free_time[0] = i;

      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
//      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
      next_free_time[next_worker] += duration;
    }
  }

  void AssignJobs(){
    next_freee_time.resize(num_workers_);
    
    assigned_workers_.resize(jobs_.size());
    start_times_.resize((jobs_.size()));
    
    /*for (int i = 0; i < num_workers_; ++i)
    {
      next_freee_time[i].workers = i;
      next_freee_time[i].next_time = jobs_[i];
      assigned_workers_[i] = i;
      start_times_[i] = 0;
    }

    for (int i = next_freee_time.size()/2 ; i > 0; --i)
      SiftDown(i);
    */


    //vector<long long> next_free_time(num_workers_,0);
    for (int i = 0 ; i < jobs_.size(); ++i)
    {
      if (i < num_workers_)
        next_freee_time[0].workers = i;


      assigned_workers_[i] = next_freee_time[0].workers;
      start_times_[i] = next_freee_time[0].next_time;
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
      if (next_freee_time[0].next_time == std::numeric_limits<int>::max())
        next_freee_time[0].next_time = jobs_[i];
      else{
        next_freee_time[0].next_time += jobs_[i];
      }
      
      
      
      SiftDown(1);

     /* for (int j = 0; j < next_freee_time.size(); j++){
        if(next_freee_time[j] < next_freee_time[next_worker])
          next_worker = j;
      }
      
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;   

      next_freee_time[0].workers =  
      next_freee_time[0].next_time += duration;
      SiftDown(1);
    */
    }
    
  }


  int Insert(long long p){
    if(next_freee_time.capacity() == next_freee_time.size())
      return 1;
    next_freee_time[next_freee_time.size()-1].next_time = p;
  }

  int Parents(int i){
    return i/2;
  }

  int LeftChild(int i){
    return (2*i);
  }

  int RightChild(int i){
    return (2*i)+1;
  }

  void SiftUp(int i){
    while (i > 1 && next_freee_time[Parents(i)].next_time > next_freee_time[i].next_time){
      swap(next_freee_time[Parents(i)].next_time, next_freee_time[i].next_time);
      swap(next_freee_time[Parents(i)].workers, next_freee_time[i].workers);
      i = Parents(i);
    }
    
  }

  void SiftDown(int i){
    int MinIndex = i;
    int l = LeftChild(i);
    if (l <= next_freee_time.size() && next_freee_time[l-1].next_time < next_freee_time[MinIndex-1].next_time)
      MinIndex = l;
    int r = RightChild(i);
    if(r <= next_freee_time.size() && next_freee_time[r-1].next_time < next_freee_time[MinIndex-1].next_time)
      MinIndex = r;
    if (MinIndex != i){
      swap(next_freee_time[MinIndex-1].next_time, next_freee_time[i-1].next_time);
      swap(next_freee_time[MinIndex-1].workers, next_freee_time[i-1].workers);
      SiftDown(MinIndex);
    }
 
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    //WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
