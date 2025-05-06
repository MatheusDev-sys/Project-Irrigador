# Projeto: Sistema de Irrigação Automatizado 🌱

Este projeto foi criado como solução para um problema real no SENAI Centro 4.0, onde a irrigação de flores era feita manualmente. Desenvolvi esse sistema como base para automatizar a leitura da umidade do solo e acionar alertas caso os níveis estejam fora do ideal.

## 🔧 Funcionalidades
- Leitura de 4 sensores de umidade
- Alerta caso a umidade esteja fora dos parâmetros definidos
- Interface via terminal simulando um painel

## 📁 Estrutura do Projeto
- `irrigacao.c`: código principal
- `Apresentacao_Projeto_irrigação_equipe07.pptx`: slides da apresentação (mover para a pasta `docs/` se preferir)

## ▶️ Como compilar
Se estiver usando Linux:
```bash
gcc irrigacao.c -o irrigador
./irrigador
