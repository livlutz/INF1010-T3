# importando a biblioteca para desenhar gráficos

import matplotlib.pyplot as plt

# valores de entrada
x = [128,256,512]

# tempo de execução de cada valor em ms
y = []

# desenhando os pontos
plt.plot(x, y)

# nomeando o eixo x para o tamanho da entrada

plt.xlabel('Tamanho da entrada')

# nomeando o eixo y para o tamanho da entrada

plt.ylabel('Tempo de execução')

# desenha o gráfico na tela
plt.show()
