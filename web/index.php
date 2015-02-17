<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8" />
<title>Projekt iz kolegija Metaheuristike</title>
<link rel="stylesheet" href="css/reset.css" />
<link rel="stylesheet" href="css/text.css" />
<link rel="stylesheet" href="css/960.css" />
<link rel="stylesheet" href="css/demo.css" />

<script>

function changeImage()
	{
	var x = document.getElementById("mySelect").value;
	if (x==1)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija1.png\">";
	    document.getElementById("functionDescription").innerHTML = "Funkcija je konveksna i glatka te se smatra jednostavnim zadatkom za evolucijske i heuristicke algoritme. Funkcija ima globalni minimum u f(0)=0 i tražena točnost je 1.e - 3.";
	    }
	else if (x==2)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija2.png\">";
	    document.getElementById("functionDescription").innerHTML = "Rosenbrockova dolina ili, kako je neki zovu, Banana funkcija ima dvije varijable ali je uvijek smatrana teškim minimizacijskim problemom. Njezin globalni minimum je f(1)=0 i leži u ravnoj, uskoj paraboličnoj dolini. Tražena točnost je 1.e - 3 i D = 30.";
	    }
	else if (x==3)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija3.png\">";
		document.getElementById("functionDescription").innerHTML = "Ova funkcija je primjer problema ravne površine. Ovaj tip problema pretraživanja prostora nam ne daje ikakvu informaciju o smjeru u kojem bi se trebali kretati. Stoga, večina konvencionalnih matematičkih metoda kao Newtonova metoda suočavaju se s velikim preprekama u ovakvim slučajevima. Stohastičke metode se ne suočavaju s puno problema u ovom slučaju jer one ne razmatraju matematičko ponašanje površine. The waveform  ove funkcije prikazane na slici iznad, tražena točnost je 1.e - 3 i D = 5.";
	    }
	else if (x==4)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija4.png\">";
		document.getElementById("functionDescription").innerHTML = "Ova funkcija prezentira stanje zvukova. Algoritam nikada ne dobije istu vrijednost za istu točku. Zapravo, ovakav tip testne funkcije razvija mogučnosti algoritma kada the data is noisy. Globalni minimum se pojavljuje u f (-5 - e) = 0 dok e ϵ (0,0.12] tražena točnost je to 1.e - 5. ";
	    }
	else if (x==5)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija5.png\">";
		document.getElementById("functionDescription").innerHTML = "Nekoliko oštrih lokalnih optimuma čini teškim pronalazak globalnog optimumu. Pošto svaka okolina lokalnih optimuma konvergira u dani lokalni optimum, većina algoritama 'zaglavi' u tom lokalnom optimumu. Globalni optimum se postiže u f(-32, -32) ≈ 0.998 tražena točnost je 0.998.";
	    }
	else if (x==6)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija6.png\">";
		document.getElementById("functionDescription").innerHTML = "Ova funkcija se uvijek smatrala pametnim evaluator za ponašanje optimizatora posebno za stohastičke i heurističke algoritme kao što je Differential Evolution and Particle Swarm Optimization. Ova valovita funkcija ia globalni minimum u f(0) = 0. Tražena točnost je 1.e - 6.";
	    }
	else if (x==7)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija7.png\">";
		document.getElementById("functionDescription").innerHTML = "Ova funkcija ispituje optimizacijske algoritme po njihovoj dimenzionalnosti, na prvu, a onda po pripadajućoj trigonometisjkoj funkcji. Globalni minimum se postiže u  f(0) = 0 i tražena točnost je 10^(-4) i D = 10.";
	    }
	else if (x==8)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija8.png\">";
		document.getElementById("functionDescription").innerHTML = "Ovu funkciju je predstavio Griewank u 1981 kako bi bila korištena kao testna funkcija za optimizacijske algoritme. Teško je pronaći globalni optimum u f(0) = 0, kada postoji više lokalnih optimuma. Tražena točnost je 1.e - 3.";
	    }
	else if (x==9)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija9.png\">";
		document.getElementById("functionDescription").innerHTML = "Dimenzionalnost je važan izazov ove funkcije kao i Rastriginove funkcije. Globalni optimum je f(0) = 0, tražena točnost je is 1.e - 3 i D = 30.";
	    }
	else if (x==10)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija10.png\">";
		document.getElementById("functionDescription").innerHTML = "Kada je Ackley predstvaio funkciju prvi put, ona je bila dvodimenzionalni optimizacijski problem. Poslije 10 godina, Beak proširuje funkciju na n-dimenzionalni problem. Tražena točnost je 1.e - 3 i D = 30.";
	    }

	}

</script>

</head>
<body>
<div class="container_12 marginTop50">
	<div class="meniLine">
		<div class="grid_2 meniTab current">
			<p>
      			Naslovnica
	      	</p>
		</div>
		<a href="results.php">
		<div class="grid_2 meniTab current">
			<p>
      			Download rezultata
	      	</p>
		</div>
		</a>
        <a href="projekt.zip">
		<div class="grid_2 meniTab current">
			<p>
      			Download projekta
	      	</p>
		</div>
		</a>
		<!-- <div class="grid_2 meniTab">
			<p>
      			Meni tab 3
	      	</p>
		</div>
		<div class="grid_2 meniTab">
			<p>
      			Meni tab 4
	      	</p>
		</div>
		<div class="grid_2 meniTab">
			<p>
      			Meni tab 5
	      	</p>
		</div>
		<div class="grid_2 meniTab">
			<p>
      			Meni tab 6
	      	</p>
		</div> -->
	</div>
	
    <?php
    if (isset($_GET['ob']))
        if ($_GET['ob']==1)
            print '
                <div class="container_12 marginTop50" style="text-align: center; font-size: 20px; margin-bottom: 20px;">
                    Molimo unesite sve numeričke vrijednosti!
                </div>
                ';
        
    ?>
    
	<div class="grid_7">
    	<p id="divImage">
			<img src="images/funkcija1.png" />
		</p>
	</div>
	
	<form action="exe.php" method="POST" name="Form" onsubmit="return validateForm()">
	<div class="grid_5">
		<div class="formInput">
			<div class="firstForm">
			
				<div class="half">Izbor funkcije: </div>
				<div class="half">
					<select name="funkcija" id="mySelect" onchange="changeImage()">
						<option value="1">De Jong function 1</option>
						<option value="2">De Jong function 2</option>
						<option value="3">De Jong function 3</option>
						<option value="4">De Jong function 4</option>
						<option value="5">De Jong function 5</option>
						<option value="6">Schaffer function 6</option>
						<option value="7">Rastrigin function</option>
						<option value="8">Griewank function</option>
						<option value="9">Hyper-Ellipsoid function</option>
						<option value="10">Ackley function</option>
					</select>
				</div>
				
				<div class="half">Broj iteracija:</div>
				<div class="half"><input type="text" name="iteracije" id="iteracije" placeholder="od 1 do 10 000"/></div>

				<div class="half">Broj ponavljanja:</div>
				<div class="half"><input type="text" name="ponavljanja" placeholder="od 2 do 100"/></div>

				<div class="half">Broj čestica:</div>
				<div class="half"><input type="text" name="n" placeholder="od 30 do 300"/></div>
				
			</div>
			<div class="secondForm">
				<div class="half">(PSO) Omega: </div>
				<div class="half"><input type="text" name="omega" placeholder="od 0.4 do 1" /></div>
				<div class="half">(PSO) ro-p: </div>
				<div class="half"><input type="text" name="ro_p" placeholder="od 0.7 do 1.3" /></div>
				<div class="half">(PSO) ro-g: </div>
				<div class="half"><input type="text" name="ro_g" placeholder="od 0.7 do 1.3" /></div>
				
				<div class="half"></div>
				<div class="half"></div>
				
				<div class="half">(ABC) m:</div>
				<div class="half"><input type="text" name="m" placeholder="2 - br. cestica / 2"/></div>
				<div class="half">(ABC) e:</div>
				<div class="half"><input type="text" name="e" placeholder="od 1 do m/2"/></div>

				<div class="half"></div>
				<div class="half"></div>

				<div class="half"></div>
				<div class="half"><input type="submit" value="POŠALJI"/></div>
				 
			</div>
		</div>
	</div>
	</form>
	<div class="grid_12 description">
		<div class="paddingDescription" id="functionDescription">
			Funkcija je konveksna i glatka te se smatra jednostavnim zadatkom za evolucijske i heuristicke algoritme. Funkcija ima globalni minimum u f(0)=0 i tražena točnost je 1.e - 3.
		</div>
	</div>

	<div class="grid_12 marginTop50">
		<?php include_once ("function_arrays.php"); ?>
		<?php include ("charts/chart1.php"); ?>
		<?php include ("charts/chart2.php"); ?>
		<?php include ("charts/chart3.php"); ?>
		
  	</div>
    
</div>
   
        

</body>
</html>
