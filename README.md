### To compile and run. 
1) make clean
2) make
3) ./bin/main

### To debug.
1) make clean
2) make debug
3) gdb ./bin/main

### Smart Algorithm Idea:
- The algorithm has two objectives: 1) discover the entire layout of the house as efficiently as possible and 2) clean the house completely.
- To achieve #1, visiting spaces in DFS manner likely prevails over BFS, because BFS requires a significant amount of backtracking.
  As the robot moves around the house in DFS manner, keep track of visited spaces and dirt level. 
  To determine if a particular space is worth visiting, it must meet one of two criteria: 1) it is unvisited or 2) it was visited before, BUT with a lower battery charge than the robot would currently carry if it moved there. 
- To achieve #2, put off cleaning until all spaces that are capable of being cleaned are visited. 
  Then, use Diijstra's shortest path algorithm to reach every valid space with dirt. 
- Note that this algorithm idea works better for a larger graph, where it more valuable to "waste" some battery to first understand the full layout of the house. 
  Furthermore, it does not guarantee the whole house will be clean. If there are valid spaces that take the entire capacity of the battery to reach and back, there is no surplus battery to clean the space.  
  Also, if a particular space is unreachable (i.e. the valid spaces of the house do not comprise a connected graph), then the whole house cannot be cleaned.
