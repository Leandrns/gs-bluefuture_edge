<h1 align="center">Global Solution - Blue Future</h1>
<h2 align="center">Entrega da disciplina de Edge Computing</h2>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/2b5e0e2e-151a-433a-bea0-c9e276e35967">
</div>

### Tecnologias
![Arduino](https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
<br><br>
Simulação no Wokwi [aqui](https://wokwi.com/projects/399868046436115457)

## Integrantes:
<p>Caio Alexandre dos Santos - RM: 558460</p>
<p>Leandro do Nascimento Souza - RM: 558893</p>
<p>Rafael de Mônaco Maniezo - RM: 556079</p>

## Sobre o projeto
A falta de conscientização da população sobre os oceanos é uma questão crucial que contribui para a falta de engajamento na preservação e proteção dos ecossistemas marinhos. Para abordar esse desafio, surge o SeaConnect, uma plataforma na qual a população e as empresas que estão situadas em regiões próximas ao mar possam se conectar. A plataforma apresenta um recurso comum a todos os usuários: uma visualização de dados coletados de diferentes pontos do oceano através de boias oceânicas e esses dados são tratados e publicados na plataforma em formas de visualizações interativas e intuitivas.

## Funcionalidades

- <p>O protótipo da boía mostra os dados atualizados da qualidade da água e os níveis de oxigênio dissolvido, pH, turbidez, salinidade, quantidade de microplásticos na água e temperatura.</p>

Para cada valor, foram determinados os seguintes parâmetros:
- **Oxigênio dissolvido**: caso esteja entre 5mg/L e 6mg/L, o estado está OK;
- **pH**:  caso esteja entre 8 e 8.3, o pH está OK;
- **Turbidez**: caso esteja menor que 50 NTU o estado está OK;
- **Salinidade**: caso esteja entre 33% e 37%, o estado está OK;
- **Quantidade de microplásticos na água**: caso esteja menor de 300g o estado está OK.
- **Temperatura**: caso esteja entre 25°C e 27°C, a temperatura está OK;

Caso algum dado fique fora da normalidade, aparecerá o estado RUIM.

## Componentes
<h3>Foram usados os seguintes componentes disponíveis na plataforma Wokwi:</h3>

- <p>Estão enfileirados 5 Potenciômetros para o usuário simular da direita para a esquerda: Oxigênio dissolvido; pH; Turbidez; Salinidade; Quantidade de microplásticos na água (respectivamente).</p>

- <p>Breadboard do tamanho HIGH<p>
- <p>Arduino Uno Rev3</p>
- <p>28 cabos jumpers</p>
- <p>1 resistor de 1kΩ</p>
- <p>1 display ILI9341 2.8"TFT-LCD</p>
- <p>1 DS18B20 Sensor de temperatura</p>

## Requisitos
-  É necessário acessar a plataforma Wokwi através do [link](https://wokwi.com/projects/399868046436115457) do projeto.
- <p>Não é preciso criar uma conta no Wokwi para fazer a simulação;<p>
- Wokiwi pode ser acessado em qualquer navegador.

- <p>É necessário instalar as seguintes bibliotecas na aba Project Libraries: OneWire, DallasTemperature e Adafruit ILI9341</p>

## Instruções de Uso - Simulação
<p>Ao acessar o link da simulação anexado acima, você é redirecionado ao site do Wokwi, podendo visualizar o circuito completo e o código fonte. Para fazer a simulação, siga o passo a passo:</p>
<p><b>1° passo:</b><br>
Clique no botão de play localizado no canto superior esquerdo da visualização do circuito.</p>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/2752e0f7-a590-4bd5-9909-1787f6258f48" width="700px">
</div><br>

<p><b>2° passo:</b><br>
Execute ações com os potenciômetros para mudar os resultados exibidos no display.<br>
Exemplo: para mudar o valor do pH, modifique o segundo potenciômetro pressionando e movimentando o mouse.</p>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/dd1039c9-4410-4722-9d30-9e543e54e231" width="600px">
</div><br>

<p><b>3° passo:</b><br>
Execute ações com o sensor de temperatura e modifique seu valor lido. Para isso, primeiro clique no sensor e depois mexa na barra de valores.</p>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/1cca0740-6bf4-4b1f-8b7f-c1cbe894bdb1" width="400px">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/fd29b06c-3dcc-4ba6-9f40-0dfb68ada136" width="500px">
</div><br>

<p><b>4° passo:</b><br>
Você pode reiniciar, finalizar ou pausar a simulação, clicando nos botões localizados no canto superior esquerdo, respectivamente.</p>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/e93d76b1-f9da-43b4-88c2-b6febc8b0861" width="400px">
</div>

## Anexos
<hr>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/290c15d5-bc75-45af-ad78-4ffe021a0415">
</div>
<hr>
<div align="center">
  <img src="https://github.com/Leandrns/gs-bluefuture_edge/assets/162998083/f32d2337-51d8-4cbe-b689-6385ac3e81d5" width="600px">
</div>
<hr>
