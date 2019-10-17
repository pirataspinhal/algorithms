#Maximum Bipartite Matching Problem

UNMATCHED = -1
matched = [UNMATCHED] * 10001
visited = [False] * 10001
adjacencyList = [0] * 10001


def augmentPath(node):
	
	global matched
	global visited
	global adjacencyList
	global UNMATCHED
	
	visited[node] = True
	
	for adjacent in adjacencyList[node]:
		
		if not visited[adjacent]:
			
			if metched[adjacent] == UNMATCHED:
				
				metched[node] = adjacent
				matched[adjacent] = node
				
				return True
			
			elif matched[adjacent] != node:
				
				if augmentPath(matched[adjacent]):
					
					metched[node] = adjacent
					matched[adjacent] = node
					
					return True
	
	return False

def resetVisited():	
	
	global visited
	
	for i in xrange(10001):
		
		if visited[i]: visited[i] = False
		

def countMacthes():
	
	global visited
	global matched
	global adjacencyList
	global UNMATCHED
	
	count = 0
	
	for i in xrange(10001):
		
		if matched[i] == UNMATCHED:	
			
			resetVisited()

			if augmentPath(i): count += 1
	
	return count


	
	
					
