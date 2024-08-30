def merge(a):
	a.sort()
	res = []
	for i in a:
		if not res or i[0]>res[-1][1]:
			res.append(i[:])
		else:
			res[-1][1] = max(res[-1][1], i[1])

	working = res[0][1] - res[0][0]	
	absence = None
	for i in range(1, len(res)):
		if absence is None:
			absence = res[i][0] - res[i-1][1]
		working = max(working, res[i][1]-res[i][0])
		absence = max(absence, res[i][0]-res[i-1][1])
	return working, absence

print(merge(
	[
	[0, 1800],
	[300, 1000], 
	[700, 1200], 
	]
))
