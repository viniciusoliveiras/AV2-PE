# Trabalho Acadêmico AV2-PE

<h2>Questão 1 – Valor: 2,0 pontos</h2>
<p>Faça um algoritmo que crie e implemente uma agenda eletrônica. Agenda deverá armazenar no máximo 100 elementos, contendo nome, idade, telefone e e-mail cada. O programa deve ter um menu com as seguintes opções (UTILIZE FUNÇÕES):</p>
<dl>
	<dt>&emsp;&emsp;&emsp;&emsp;&emsp;Adicionar:</dt>
		<dd>Adiciona uma entrada na agenda com o nome, idade, telefone e e-mail de uma pessoa</dd>
	<dt>&emsp;&emsp;&emsp;&emsp;&emsp;Pesquisar:</dt>
		<dd>Pesquisar pelo nome de um usuário. Exiba todas as informações de pessoas com o nome pesquisado</dd>
	<dt>&emsp;&emsp;&emsp;&emsp;&emsp;Exibir:</dt>
		<dd>Exiba todas as informações de pessoas da agenda eletrônica.</dd>
</dl>


<h2>Questão 2 – Valor: 3,0 pontos</h2>
<p>Faça um programa, utilizando o Dev-C++, para armazenar os dados de um aluno(a), contendo os seguintes dados:</p>
<blockquote>
	<h4 align="center">
		matricula: inteiro<br/>
		nome: caractere<br/>
		sexo: caractere<br/>
		idade: inteiro<br/>
		av1, av2, av3 e media: real	(UTILIZE UMA MATRIZ PARA ARMAZENAR AS NOTAS)
	</h4>
</blockquote>

<p>O usuário poderá armazenar no máximo 50 alunos. O programa terá a opção de adicionar, exibir ou salvar/carregar os dados. O programa deverá ter as seguintes condições:</p>

<h4><em>&emsp;&emsp;Adicionar:</em></h4>
<dl>
	<dd>Efetua uma pesquisa para saber se o aluno(a) existe ou não no vetor através da matrícula do mesmo:</dd>
	<dd>&emsp;•&emsp;Se existir, informar que o aluno(a) já se encontra presente e não adicione</dd>
	<dd>&emsp;•&emsp;Caso não exista, verifique se o sistema está ou não lotado antes de inseri</dd>
	<dd>Ao armazenar as notas utilize o mesmo critério de avaliação da UniCarioca para calcular a média, está não deve ser informada pelo aluno (Soma das 2 maiores notas divididos pela quantidade).</dd>
</dl>

<h4><em>&emsp;&emsp;Exibir:</em></h4>
<dl>
	<dd>O usuário poderá exibir os alunos(as) com os seguintes critérios de média:</dd>
	<dd>&emsp;•&emsp;Alunos reprovados com média inferior a 5</dd>
	<dd>&emsp;•&emsp;Alunos reprovados com média inferior a 7</dd>
	<dd>&emsp;•&emsp;Alunos reprovados</dd>
	<dd>&emsp;•&emsp;Alunos aprovados com média superior ou igual a 7</dd>
	<dd>&emsp;•&emsp;Alunos aprovados com média superior ou igual a 9</dd>
	<dd>&emsp;•&emsp;Alunos aprovados</dd>
	<dd>&emsp;•&emsp;Todos os alunos</dd>
</dl>

<h4><em>&emsp;&emsp;Salvar/Carregar</em></h4>
<dl>
	<dd>O usuário irá escolher entre salvar ou carregar um arquivo externo</dd>
	<dd>&emsp;•&emsp;Colocar um campo para o usuário informar o nome do arquivo externo, tanto na opção de salvar quanto carregar</dd>
	<dd>&emsp;•&emsp;Ao selecionar a opção de carregar dados, o sistema deve ler todas as informações do arquivo externo e adicionar no programa</dd>
</dl>


<h2>Questão 3 – Valor: 3,0 pontos</h2>
<p>Faça um programa, utilizando o Dev-C++, para armazenar os dados de um funcionário(a), contendo os seguintes dados:</p>
<blockquote>
	<h4 align="center">
		CPF: inteiro<br/>
		nome: caractere<br/>
		sexo: caractere<br/>
		idade: inteiro<br/>
		horas trabalhadas: real<br/>
		valor hora trabalhada: real<br/>
		salário líquido: real (DEVE SER CALCULADO ATRAVÉS DA QUANTIDADE DE HORAS, VALOR DA MESMA E TABELA DO INSS)
	</h4>
</blockquote>

<p>O usuário poderá armazenar no máximo 50 funcionários. O programa terá a opção de adicionar, buscar, exibir ou salvar/carregar os dados. O programa deverá ter as seguintes condições:</p>

<h4><em>&emsp;&emsp;Adicionar:</em></h4>
<dl>
	<dd>Efetuar uma pesquisa para saber se o funcionário(a) existe ou não no vetor através do CPF do mesmo</dd>
	<dd>&emsp;•&emsp;Se existir, informar que o funcionário(a) já se encontra presente e não adicione</dd>
	<dd>&emsp;•&emsp;Caso não exista, verifique se o sistema está ou não lotado antes de inserir</dd>
	<dd>Para calcular o salário líquido utilize os valores informados na quantidade de horas trabalhadas, o valor da hora e a tabela de desconto de INSS que se encontra abaixo:</dd>
</dl><br/>

<table align="center">
<thead>
  <tr>
    <th align="center">SALÁRIO DE CONTRIBUIÇÃO (R$)</th>
    <th align="center">ALÍQUOTA INSS</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td align="center">até 1.751,81</td>
    <td align="center">8%</td>
  </tr>
  <tr>
    <td align="center">de 1.751,82 até 2.919,72</td>
    <td align="center">9%</td>
  </tr>
  <tr>
    <td align="center">de 2.919,73 até 5.839,45</td>
    <td align="center">11%</td>
  </tr>
</tbody>
</table>

 
<h4><em>&emsp;&emsp;Pesquisar:</em></h4>
<dl>
	<dd>A pesquisa será realizada utilizando o CPF do funcionário(a)</dd>
	<dd>&emsp;•&emsp;Caso não exista, informe que o funcionário não está matriculado e pergunte se o usuário deseja adicionar no sistema.</dd>
</dl>

<h4><em>&emsp;&emsp;Exibir:</em></h4>
<dl>
	<dd>O usuário poderá exibir os funcionários(as) com os seguintes critérios de salário:</dd>
	<dd>&emsp;•&emsp;Funcionários com salário inferior a R$ 500</dd>
	<dd>&emsp;•&emsp;Funcionários com salário inferior a R$ 1000</dd>
	<dd>&emsp;•&emsp;Funcionários com salário superior a R$ 4000</dd>
	<dd>&emsp;•&emsp;Funcionários com salário superior ou igual a R$ 5000</dd>
	<dd>&emsp;•&emsp;Funcionários com salário superior ou igual a R$ 7000</dd>
	<dd>&emsp;•&emsp;Funcionários com salário superior ou igual a R$ 10000</dd>
	<dd>&emsp;•&emsp;Todos os funcionários</dd>
</dl>

<h4><em>&emsp;&emsp;Salvar/Carregar:</em></h4>
<dl>
	<dd>O usuário irá escolher entre salvar ou carregar um arquivo externo</dd>
	<dd>&emsp;•&emsp;Colocar um campo para o usuário informar o nome do arquivo externo, tanto na opção de salvar quanto carregar</dd>
	<dd>&emsp;•&emsp;Ao selecionar a opção de carregar dados, o sistema deve ler todas as informações do arquivo externo e adicionar no programa</dd>
</dl>
