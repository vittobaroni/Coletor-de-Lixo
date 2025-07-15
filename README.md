<h1>Coletor de Lixo</h1> 
 <r>Coletor de Lixo em C, feita de forma visível e didática.</r> <br><br>
O processo utilizou várias ferramentas da Linguagem C, especificamente BDWGC, que é um coletor de lixo conservador e incremental automático . Sua função é gerenciar a memória alocada dinamicamente, identificando e liberando automaticamente blocos de memória que não estão mais em uso pelo programa <br><br>

Código se encontra em meu_exemplo.c  . Espero que gostem ! <br><Br>

Passo a Passo --> Baixe o repositório, vá para a pasta do diretório teste-gc no cmd ( recomendado o x64 native tools do visual studio 2022 ), digite "nmake", meu_exemplo.exe, e quando sair "nmake clean" para limpar os arquivos desnecessários

ATUALIZAÇÃO : Foi criado um arquivo chamado explicacao.c, que mostra como é realmente feito o processo da coleta, já que o coletor é do tipo mark and sweep . Basta digitar "nmake" e seguir o mesmo método de antes

<p>Inspiração no repositório de Ivan Maidanski, disponível neste <a href = "https://github.com/ivmai/bdwgc">Link </a> </p>
