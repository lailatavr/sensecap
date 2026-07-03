# SenseCap - Sensor de proximidade para pessoas com deficiência visual


Protótipo vestível de baixo custo para detecção de obstáculos na altura do tronco e da cabeça, desenvolvido como complemento à bengala tradicional.


## Motivação

Pessoas com deficiência visual utilizam a bengala para detectar obstáculos no chão, mas ficam expostas a objetos na altura do tronco e da cabeça (como placas, galhos, espelhos retrovisores, etc). Com isso, o SenseCap é um dispositivo vestível fixado em uma touca que cobre essa zona cega, emitindo alertas sonoros proporcionais à distância do obstáculo detectado.


## Funcionamento

O sensor ultrassônico HC-SR04 emite pulsos de som e mede o tempo de retorno do eco para calcular a distância até o obstáculo mais próximo. Quando um objeto é detectado a 50 cm ou menos, o buzzer é ativado com frequência de bipe proporcional à proximidade: quanto mais perto, mais rápido o bipe.


## Componentes

- Arduino Nano (ATmega328P); 

- Sensor de distância HC-SR04 (alcance de até 400 cm); 

- Buzzer ativo; 

- Bateria Li-Po PL401223GH - 3,8V e 130 mAh;

- Módulo de carga TP4056;

- Touca comum.


## Pinagem (Arduino Nano)

<table rules="rows" style="border-collapse: collapse; width: 100%;">
  <thead>
    <tr style="border-bottom: 2px solid #555;">
      <th align="left" style="padding: 8px;">Pino do Arduino Nano</th>
      <th align="left" style="padding: 8px;">Função</th>
    </tr>
  </thead>
  <tbody>
    <tr style="border-bottom: 1px solid #444;">
      <td style="padding: 8px;">D2</td>
      <td style="padding: 8px;">TRIG - disparo do sensor</td>
    </tr>
    <tr style="border-bottom: 1px solid #444;">
      <td style="padding: 8px;">D3</td>
      <td style="padding: 8px;">ECHO - leitura do eco</td>
    </tr>
    <tr style="border-bottom: 1px solid #444;">
      <td style="padding: 8px;">D4</td>
      <td style="padding: 8px;">Buzzer (sinal)</td>
    </tr>
    <tr style="border-bottom: 1px solid #444;">
      <td style="padding: 8px;">VIN</td>
      <td style="padding: 8px;">Alimentação do HC-SR04</td>
    </tr>
    <tr style="border-bottom: 1px solid #444;">
      <td style="padding: 8px;">GND</td>
      <td style="padding: 8px;">Terra</td>
    </tr>
  </tbody>
</table>



## Esquemático

<img width="1047" height="642" alt="Captura de tela 2026-07-01 234252" src="https://github.com/user-attachments/assets/cd324801-19f7-4fee-b52f-79145465d168" />



## Código

Todo o firmware encontra-se em touca.ino. 



## Como usar


- Carregue a bateria via USB-C no módulo TP4056 (LED vermelho = carregando, LED azul = completo);

- Ligue o dispositivo;
  
- Fixe a touca com o sensor apontado para frente, na altura do rosto;
  
- O buzzer bipa automaticamente ao detectar obstáculos a 50 cm ou menos.



## Melhorias previstas


 - Sensores menores/múltiplos;
   
 - Bluetooth e alerta por vibração;
 
 - Tornar o dispositivo mais discreto e confortável.
   

### Projeto desenvolvido no contexto da disciplina "Projetos e Inovações em Engenharia de Reabilitação e Tecnologias Assistivas" (ENG075) do Departamento de Engenharia Elétrica da Escola de Engenharia da UFMG.
