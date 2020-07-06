# -*- encoding:utf-8 -*-


impar = lambda n : 2 * n - 1

header = """
	Demostrar que es cierto:

	1 + 3 + 5 + ... + (2*n)-1 = n ^ 2
	
	Luego con este programa se busca probar dicha afirmacion.
"""

def suma_impares(n):
	suma = 0
	for i in range(1, n+1):
		suma += impar(i)
	return suma


def main():
	print(header)
	num = int(input('Numero: '))
	
	suma = suma_impares(num)
	cuadrado = num ** 2

	print('Suma de los ', num, ' primeros impares = ', suma)
	print('Cuadrado del numero: ', cuadrado)
	
	if suma == cuadrado:
		print('Son iguales, luego se cumple la afirmacion')
	else:
		print('No son iguales, luego no se cumple la afirmacion')



if __name__ == '__main__':
	main()


