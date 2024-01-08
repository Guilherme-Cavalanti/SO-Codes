import os 

def create_a_fork_1():
    "Função que cria um fork do processo a ser executado" 
    n = os.fork() 
    if n > 0: 
        "Execução do Processo Pai"
        print("Hello World") 
    elif n == 0: 
        "Execução do Processo Filho"
        print("Hello World") 
    else:
        print("Criação do Filho Falhou")
  
def create_a_fork_2():
    "Função que cria um fork do processo exibindo o id do processo" 
    n = os.fork() 
    if n > 0: 
        "Execução do Processo Pai"
        print("Hello World", os.getpid()) 
    elif n == 0: 
        "Execução do Processo Filho"
        print("Hello World", os.getpid()) 
    else:
        print("Criação do Filho Falhou")

create_a_fork_2()