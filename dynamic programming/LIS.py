#Longest increasing subsequence/
#implementacao bottom-up

def LIS():
	
	global array
	global dp
	
	for i in xrange(1, tamanho):
		
		for j in xrange(i):
			
			if array[j] < array[i]:
				
				if dp[i] < dp[j] + 1:
					
					dp[i] = dp[j] + 1
	

def maiorSequencia():
	
	global dp
	
	maior = 0
	
	for e in dp:
		
		maior = max(e, maior)
	
	return maior
	
tamanho = int(raw_input())
array = map(int, raw_input().split())

dp = [1] * tamanho
LIS()

print maiorSequencia()
