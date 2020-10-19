#Alunos: Icaro Peretti e Eduardo Rampon
import os

#Pede para o usário digitar uma palavra
palavra = str(input("Digite a palavra secreta:")).upper() #upper para que seja sempre letras maiusculas

list(palavra) #transforma a string em uma lista para que separe letra por letra,ex: ["A","B"]

os.system("cls") #Limpar o console para que a palavra secreta não fique aparecendo na tela

#Pede para o usuário dar uma dica, do que a palavra se trata
dica = str(input("De uma dica sobre a palavra: "))
print("Dica: ", dica)

letrasDescobertas = [] #lista para guardas as letras que forem encontrads
print("\nJogo da Forca\n")

#Coloca traços nas letras que ainda nao foram encontratas
for i in range(0,len(palavra)):
    letrasDescobertas.append("-")

letraExiste = False #inicia as letras existentes como falsa

#Enquanto a palavra nao estiver completa,continua pedindo para o usuario digitar
while letraExiste == False:
    letra = str(input("Digite uma letra: ")).upper() #upper para que seja sempre letras maiusculas
    #Avisa para o usuario digitar apenas uma letra por vez
    if (len(letra) > 1):
        print("Digte apenas uma letra por vez!\n")
    #Percorre a palavra a ser formada e verifica se a letra digitada faz parte
    for i in range(0,len(palavra)): 
        if letra == palavra[i] : 
            letrasDescobertas[i] = letra #Se for encontrada,substitui traço pela letra correspondente

        print(letrasDescobertas[i]) #Imprime as letras descobertas
    letraExiste = True 

    #Percorre as letras descobertas e verifica se ainda existem traços
    #se existir significa que a palavra ainda não esta completa
    for j in range(0,len(letrasDescobertas)):
        if letrasDescobertas[j] == "-" :
            letraExiste = False

print("A palavra era", palavra)

input("Digite qualquer tecla para encerrar:")
