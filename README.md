# SMART_LEARN_ENGLISH
Smart learn english é uma aplicação desktop constituido por três modulos de English com um chat de Inteligência Artificial, que certamente poderia ser desenvolvida como uma aplicação web, porém abracei o desafio de fazer - lô em C++, desde a requisição a serilização e deserialização do json, e com uma interface grafica baseada na mesma biblioteca gtkmm utilizada pelo Gnome (linuz) . A ideia de uma aplicação desktop foi fortemente motivado pelo facil acesso que qualquer um que quisesse ter a aplicação pode simplemente baixar e instalar pelo link: git@github.com:KalengaAO/SMART_LEARN_ENGLISH.git 

## Dependências

Instale as bibliotecas necessárias:

```bash
sudo apt update

sudo apt install build-essential
sudo apt install libgtkmm-4.0-dev
sudo apt install libcurl4-openssl-dev
sudo apt install nlohmann-json3-dev
```
```

---

## Configuração da API

### Modelo utilizado

API_MODELOS

https://openrouter.ai/openai/gpt-oss-120b:free

### Definir a chave da API

Antes de executar a aplicação, defina a variável de ambiente:

```bash
export OPENROUTER_API_KEY="SUA_CHAVE_AQUI"
```

Verificar se a variável foi definida:

```bash
echo $OPENROUTER_API_KEY
```

---

## Execução

```bash
./sle
```
