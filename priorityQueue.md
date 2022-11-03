# 우선순위큐

### 용어정리


    큐(Queue) : 먼저 들어온 요소가 먼저 나감. *First In First Out*
    
    우선순위큐(Priority queue) : Key값이 높은 순서대로(Sorting) 먼저 내보내는 큐

    힙(Heap) : (거의) 완전 이진 트리이고, 부모의 키값이 자식의 키값보다 같거나 큰 트리 (= Max Heap)

    반대로, 부모의 키값이 자식의 키값보다 작으면 Min Heap

    싸이클(Cycle) : 특정 정점에서 어떠한 경로를 지나 다시 그 정점으로 돌아오는 경로

  
***

### 힙
힙은 보통 **배열**을 이용해 구현한다.

→ 완전 이진 트리의 각 노드에 번호를 붙여 이를 배열의 인덱스와 동일시 시킨다.


**번호가 i인 node와 주변 관계**

root : A (첫 요소) / parent(i) : i/2 / left(i) : 2i  / right(i) : 2i + 1

***

### 우선순위큐
**함수**

1. Insert(S, x) : 집합 S에 x라는 요소를 넣는다.
2. max(S) : 집합 S의 최댓값을 구한다.
3. extract_max(S) : 2번 과정에서 구한 최댓값을 추출한다.
4. increase_key(S, x, k) : 집합 S의 key값(k)을 x로 변경한다

*C++에서는 Array Index가 0부터 시작, 우선순위큐에서는 0을 비워두고 1를 root로 하여 연산의 편리성을 추구*

**Build_Max_Heap** : Array 전체를 Max Heap으로 변경

- Convert A[1, … n] to Max Heap

    Build_Max_Heap(A) {
      for (i = n/2 ; i > 0 ; i--) Max_Heapify }

Leaf Node : n/2 + 1 … n

Leaf Node는 Max_Heapify 과정이 필요하지 않기 때문에 n/2부터 for문 시작.

**Max_Heapify** : 어떤 특정한 인덱스에 대해 그 서브트리를 Max Heap 성질에 만족하도록 바꿔주는 과정

- complete binary tree인걸 확인 후 element A[i] ≠ max_heap 인 경우
    Max_Heapify(i){
      int left = left(i);
      int right = right(i);

      if(left > right && left == right) swap(i, left);
      else if(left < right) swap(i, right); }
     
- Recursion(순환 / 재귀호출)

**Heap_Sort** : 

1. Array를 Build_Max_Heap
2. Find Max / A[i] Array의 첫 번째 요소
3. Swap A[i] , A[n] → Max Element의 위치가 맨 끝이 됨
4. Discard node n
5. Run Max_Heapify
6. Go to Step 2

*Swap : 요소들을 한 칸씩 밀게 되면 발생하는 많은 연산(n-1번)을 단 세 번으로 줄일 수 있음.*
