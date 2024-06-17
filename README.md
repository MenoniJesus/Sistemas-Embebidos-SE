**Sistema de Estacionamento com Sensor de Proximidade e Temperatura**

  Este projeto foi desenvolvido como uma atividade avaliativa da disciplina de Sistemas Embarcados, utilizando um Arduino UNO. A ideia principal é simular um sensor de estacionamento baseado em um sensor de proximidade.

**Justificativa das Três Versões**

Existem três versões do projeto devido às limitações das plataformas de simulação:

**1 - TinkerCad:** Não é possível simular o sensor de temperatura DS18B20.

**2 - Wokwi:** Não possui suporte para o extensor de portas PCF8574 necessário para controlar os LEDs.

**3 - Arduino IDE (Versão Final):** Baseada na versão do TinkerCad, mas sem o sensor de temperatura devido a problemas de funcionamento inexplicáveis na placa física após sua adição.
Descrição do Projeto

  O sistema desenvolvido utiliza um sensor de ultrassom para medir a distância de um objeto. Se a distância for menor que 100 cm (1 metro), os LEDs começam a acender e o buzzer emite sons. À medida que a distância diminui, mais LEDs acendem e o intervalo entre os sons do buzzer diminui. Um sensor de temperatura foi inicialmente adicionado como um extra, apenas para exibir a temperatura atual, mas foi removido na versão final apresentada devido a problemas de funcionamento.

**Componentes e Conexões**
 - Sensor de Temperatura DS18B20: Pino S (D9)

 - Buzzer: Pino S (D3)

 - Sensor de Ultrassom HC-SR04: Pino Trigger (D11) | Pino Echo (D12)

 - Extensor de Portas PCF8574 (para 8 LEDs): A4, A5 (SDA, SCL)

 - LCD 16x2 (I2C): Biblioteca DFRobot_RGBLCD1602.h, A4, A5 (SDA, SCL)

**Instruções para Execução**

 - TinkerCad:
Importe o código fornecido no ambiente de simulação TinkerCad.
Conecte os componentes de acordo com as portas especificadas.
Execute a simulação para verificar o funcionamento do sensor de proximidade e os LEDs.

 - Wokwi:
Importe o código fornecido no ambiente de simulação Wokwi.
Conecte os componentes de acordo com as portas especificadas, exceto o extensor de portas.
Execute a simulação para verificar o funcionamento do sensor de proximidade e o buzzer.

 - Arduino IDE:
Carregue o código fornecido no Arduino IDE.
Conecte os componentes na placa física de acordo com as portas especificadas.
Execute o código na placa física para verificar o funcionamento do sistema de estacionamento sem o sensor de temperatura.

**Problemas Conhecidos**
Versão com Sensor de Temperatura: O buzzer não alterava o intervalo de tempo entre os sons quando o sensor de temperatura estava presente. Este problema não pôde ser resolvido a tempo da apresentação, levando à remoção do sensor na versão final.

**Código**

O código completo para cada versão está disponível nos respectivos diretórios

**Conclusão**

  Apesar das limitações encontradas nas plataformas de simulação e problemas na integração do sensor de temperatura, o projeto atingiu seu objetivo principal de criar um sistema de estacionamento funcional com base em um sensor de proximidade. O uso de diferentes plataformas de simulação destacou a importância de testar e validar o código em um ambiente físico real.
