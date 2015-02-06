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
	    document.getElementById("functionDescription").innerHTML = "The first function is a convex and smooth one that is always considered a simple task to evolutionary and heuristic algorithms. This function has a global minimum at f(0)=0 and let the desired value be 1.e - 3.";
	    }
	else if (x==2)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija2.png\">";
	    document.getElementById("functionDescription").innerHTML = "The Rosenbrock’s valley or some called Banana function has two variables but always considered as a difficult minimization problem. Its global minimum is f(1)=0 and laid in a flat, narrow and parabolic shaped valley. The desired value is considered equal to 1.e - 3 and D = 30.";
	    }
	else if (x==3)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija3.png\">";
		document.getElementById("functionDescription").innerHTML = "This function is a demonstration of the flat surface problems. These types of problem search spaces do not give any information about a good direction to move to. Hence, most of conventional mathematic methods like Newton method face obstacles in such cases. The stochastic method, however, do not face much problems, since they do not consider the mathematic behaviors of the surface. The waveform of this function is shown in picture above, the desired value is set to 1.e - 3 and D = 5.";
	    }
	else if (x==4)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija4.png\">";
		document.getElementById("functionDescription").innerHTML = "This function presents a condition of existing noises. Here, an algorithm never obtains the same value in the same point. In fact, this type of test function evaluates the ability of algorithm when the data is noisy. The global minimum occurs in f (-5 - e) = 0 while e ϵ (0,0.12] and the desired value is considered equal to 1.e - 5. ";
	    }
	else if (x==5)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija5.png\">";
		document.getElementById("functionDescription").innerHTML = "Having several sharp local optimum points makes this function a difficult task for finding the global optimum. Since the neighborhood of each local optimum guides the algorithm to its leading optimum point, most of the algorithms stuck in the first local optimum point that they reach. The local optimum occurs in f(-32, -32) ≈ 0.998 and the desired value is taken equal to 0.998.";
	    }
	else if (x==6)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija6.png\">";
		document.getElementById("functionDescription").innerHTML = "This function was always considered as a wise evaluator for the behavior of optimizers especially the stochastic and heuristic algorithms such as Differential Evolution and Particle Swarm Optimization [25]102627. This wavy function has a global minimum at f(0) = 0. The desired value is set to 1.e - 6.";
	    }
	else if (x==7)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija7.png\">";
		document.getElementById("functionDescription").innerHTML = "This function challenges the optimization algorithms by its dimensionality, at first, and then by containing a trigonometric function. Picture above shows a 3D graph of this function. Except two dimensions, the other variables are set to their optimum value which is zero. The global minimum for this function is in f(0) = 0 and the desired value is set to 10^(-4) and the D = 10.";
	    }
	else if (x==8)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija8.png\">";
		document.getElementById("functionDescription").innerHTML = "This function was proposed by Griewank in 1981 to be used as a tester for optimization algorithms. Having many local optimum points makes it hard to find its global optima in f(0) = 0. Let the desired value be 1.e - 3.";
	    }
	else if (x==9)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija9.png\">";
		document.getElementById("functionDescription").innerHTML = "The dimensionality is the important challenge of this function as well as Rastrigin function. Picture above shows its 3D graph while {X3, X4, ... , X10} are kept equal to their optimum value which means zero. The global optima is in f(0) = 0, the desired value is 1.e - 3 and D = 30.";
	    }
	else if (x==10)
		{
	    document.getElementById("divImage").innerHTML = "<img src=\"images/funkcija10.png\">";
		document.getElementById("functionDescription").innerHTML = "When this function was proposed by Ackley for the first time, it was only a two dimensional minimization problem. Around ten years later, Beak extended it to a n-dimensional problem. The desired value is considered 1.e - 3 and the D = 30. Picture above shows a 3D graph for this function.";
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
		<div class="grid_2 meniTab">
			<p>
      			Meni tab 2
	      	</p>
		</div>
		<div class="grid_2 meniTab">
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
		</div>
	</div>
	
	<div class="grid_7">
    	<p id="divImage">
			<img src="images/funkcija1.png" />
		</p>
	</div>
	
	<form action="send.php" method="POST">
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
				<div class="half"><input type="text" name="iteracije" placeholder="od 1 do 10 000"/></div>

				<div class="half">Broj ponavljanja:</div>
				<div class="half"><input type="text" name="ponavljanja" placeholder="od 2 do 100"/></div>

				<div class="half">Broj čestica:</div>
				<div class="half"><input type="text" name="cestice" placeholder="od 30 do 300"/></div>
				
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
			The first function is a convex and smooth one that is always considered a simple task to evolutionary and heuristic algorithms. 
			This function has a global minimum at f(0)=0 and let the desired value be 1.e - 3.
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