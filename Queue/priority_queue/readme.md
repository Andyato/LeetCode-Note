### 优先队列底层实现
- 默认：最大堆（最大优先）priority_queue\<typename\>
- 最小优先：priority_queue\<typename, vector\<typename>, greater\<typename>>
- 自定义优先：priority_queue\<typename\, vector\<typename>, function<bool(typename, typename)>> pq(myCMP);