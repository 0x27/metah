<?php

//funkcija za izvlacenje broja ponavljanja, vraca string pripremljen za ubacivanje u js fju.
function num_repeating ($file)
	{
	$filecontents = file_get_contents("KOD/results/".$file, "r");
	$array = preg_split('/[\s]+/', $filecontents, -1, PREG_SPLIT_NO_EMPTY);

	$ponavljanja = "";
		for ($i=1; $i<=(sizeof($array)/4); ++$i)
			{
			$ponavljanja = $ponavljanja."'".$i."'";
			//provjeravamo da li se radi o zadnjem broju u nizu, jer ako da, onda ne stavljamo zarez na kraj
			if ($i!=(sizeof($array)/4))
				$ponavljanja = $ponavljanja.",";
			}
			
	return $ponavljanja;
	}
	
	
//fja za izvlacenje odredjenog elementa reda
function array_3chart ($file, $num_element)
	{
	$filecontents = file_get_contents("KOD/results/".$file, "r");
	$array = preg_split('/[\s]+/', $filecontents, -1, PREG_SPLIT_NO_EMPTY);
	
	$array_new="";
	for ($i=($num_element-1); $i<sizeof($array); $i=$i+4)
		{
		$array_new = $array_new.$array[$i];
			//provjeravamo da li se radi o zadnjem broju u nizu, jer ako da, onda ne stavljamo zarez na kraj
			if ($i!=(sizeof($array)-(5-$num_element)))
				$array_new = $array_new.", ";
		}
		
	return $array_new;
	}

	
//fja za izvlacenje odredjenog elementa reda
function array_element ($file, $num_element)
	{
	$filecontents = file_get_contents("KOD/results/".$file, "r");
	$array = preg_split('/[\s]+/', $filecontents, -1, PREG_SPLIT_NO_EMPTY);
	
	$array_new="";
	for ($i=($num_element-1); $i<sizeof($array); $i=$i+4)
		{
		$array_new = $array_new.$array[$i];
			//provjeravamo da li se radi o zadnjem broju u nizu, jer ako da, onda ne stavljamo zarez na kraj
			if ($i!=(sizeof($array)-(5-$num_element)))
				$array_new = $array_new.", ";
		}
		
	return $array_new;
	}


?>