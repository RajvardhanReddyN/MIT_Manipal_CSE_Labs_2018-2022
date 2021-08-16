import pandas as pd

data = [['Dinesh',10],['Nithya',12],['Raji',13]]
df = pd.DataFrame(data,columns=['Name','Age'])

print(df)

print(df.shape)
print(df.head())
print(df.tail())
print(df.T)
print(df[0:3])