# 图

表示多对多的关系

由一个非空的有限顶点集合和一个有限边集合组成

邻接矩阵对稠密图很合算，不适合稀疏图

**邻接表**

适合稀疏图

设立一个指针数组，数组中存每个结点的指针。

邻接表不唯一



**常见术语**

度

## 操作

1. 

## 图的遍历

1. 深度优先搜索 DFS

```
void DFS (Vertex V)
{
	visited[V] = true;
	for (V的每个邻接点W) {
		if (!visited[W]) {
			DFS(W);
		}
	}
}
```
2. 广度优先搜索 BFS
```
void BFS (MGraph G)
{   /* 按广度优先遍历图G。使用辅助队列Q和访问标志数组Visited */
    Queue  *Q;    
    VertexType  U, V, W;
    for ( U = 0; U < G.n; ++U )  
       Visited[U] = FALSE;
    Q = CreatQueue( MaxSize ); /* 创建空队列Q */
    for ( U = 0; U<G.n; ++U )
       if ( !Visited[U] ) { /* 若U尚未访问 */
           Visited[U] = TRUE; 
           printf( "visit vertex: %c\n", G.Vertices[U] );
           /* 相当于访问顶点U */
           AddQ (Q, U);    /* U入队列 */
           while ( ! IsEmptyQ(Q) ) {
              V = DeleteQ( Q );  /*  队头元素出队并置为V */
              for( W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W) )
                  if ( !Visited[W] ) {
                     Visited[W] = TRUE;
                     printf( "visit vertex: %c\n", G.Vertices[W] );
                     /* 相当于访问顶点W */
                     AddQ (Q, W);
                  }
           } /* while结束*/
} /* 结束从U开始的BFS *
```
