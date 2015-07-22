<!DOCTYPE HTML>
<html>
	<head>
		<title>Clients</title>
		<style>
			body {
				width: 600px;
				margin: 40px auto;
				font-family: Calibri;
				font-size: 14px;
				color: #bcbcbc;
				background: url('grey.jpg');
			}

			table {
				*border-collapse: collapse; /* IE7 and lower */
				border-spacing: 0;
				width: 100%;    
			}
			
			a {
				text-decoration: none;
				color: #bcbcbc;
			}

			.bordered {
				border: solid #ccc 1px;
				-moz-border-radius: 6px;
				-webkit-border-radius: 6px;
				border-radius: 6px;
				-webkit-box-shadow: 0 1px 1px #ccc; 
				-moz-box-shadow: 0 1px 1px #ccc; 
				box-shadow: 0 1px 1px #ccc;         
			}

			.bordered tr:hover {
				background: #fbf8e9;
				-o-transition: all 0.1s ease-in-out;
				-webkit-transition: all 0.1s ease-in-out;
				-moz-transition: all 0.1s ease-in-out;
				-ms-transition: all 0.1s ease-in-out;
				transition: all 0.1s ease-in-out;     
			}    
				
			.bordered td, .bordered th {
				border-left: 1px solid #ccc;
				border-top: 1px solid #ccc;
				padding: 10px;
				text-align: left;    
			}

			.bordered th {
				background-color: #dce9f9;
				background-image: -webkit-gradient(linear, left top, left bottom, from(#ebf3fc), to(#dce9f9));
				background-image: -webkit-linear-gradient(top, #ebf3fc, #dce9f9);
				background-image:    -moz-linear-gradient(top, #ebf3fc, #dce9f9);
				background-image:     -ms-linear-gradient(top, #ebf3fc, #dce9f9);
				background-image:      -o-linear-gradient(top, #ebf3fc, #dce9f9);
				background-image:         linear-gradient(top, #ebf3fc, #dce9f9);
				-webkit-box-shadow: 0 1px 0 rgba(255,255,255,.8) inset; 
				-moz-box-shadow:0 1px 0 rgba(255,255,255,.8) inset;  
				box-shadow: 0 1px 0 rgba(255,255,255,.8) inset;        
				border-top: none;
				text-shadow: 0 1px 0 rgba(255,255,255,.5); 
				color: #444;
			}

			.bordered td:first-child, .bordered th:first-child {
				border-left: none;
			}

			.bordered th:first-child {
				-moz-border-radius: 6px 0 0 0;
				-webkit-border-radius: 6px 0 0 0;
				border-radius: 6px 0 0 0;
			}

			.bordered th:last-child {
				-moz-border-radius: 0 6px 0 0;
				-webkit-border-radius: 0 6px 0 0;
				border-radius: 0 6px 0 0;
			}

			.bordered th:only-child{
				-moz-border-radius: 6px 6px 0 0;
				-webkit-border-radius: 6px 6px 0 0;
				border-radius: 6px 6px 0 0;
			}

			.bordered tr:last-child td:first-child {
				-moz-border-radius: 0 0 0 6px;
				-webkit-border-radius: 0 0 0 6px;
				border-radius: 0 0 0 6px;
			}

			.bordered tr:last-child td:last-child {
				-moz-border-radius: 0 0 6px 0;
				-webkit-border-radius: 0 0 6px 0;
				border-radius: 0 0 6px 0;
			}
			
			form{
				width:500px;
				margin:0 auto;
			}
			
			.search { 
				padding:6px 15px 6px 30px;
				margin:3px; 
				background: url('search.png') no-repeat 8px 6px; 
			}
			
			.rounded { 
				border-radius:15px; 
				-moz-border-radius:15px; 
				-webkit-border-radius:15px; 
			}
			
			input[type=button], input[type=button]:hover {
				position:relative; 
				left:-6px;
				border:1px solid #adc5cf;
				background: #e4f1f9; /* Old browsers */
				background: -moz-linear-gradient(top, #e4f1f9 0%, #d5e7f3 100%); /* FF3.6+ */
				background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,#e4f1f9), color-stop(100%,#d5e7f3)); /* Chrome,Safari4+ */
				background: -webkit-linear-gradient(top, #e4f1f9 0%,#d5e7f3 100%); /* Chrome10+,Safari5.1+ */
				background: -o-linear-gradient(top, #e4f1f9 0%,#d5e7f3 100%); /* Opera 11.10+ */
				background: -ms-linear-gradient(top, #e4f1f9 0%,#d5e7f3 100%); /* IE10+ */
				background: linear-gradient(top, #e4f1f9 0%,#d5e7f3 100%); /* W3C */
				filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#e4f1f9', endColorstr='#d5e7f3',GradientType=0 ); /* IE6-9 */
				color:#7da2aa;
				cursor: pointer;
			}
			
			.dark input[type=text]{
				border:1px solid #2a2e31;
				background-color:#2d3035;
				color:#bcbcbc;
			}
			
			#ok {
				-webkit-border-radius: 15px;
				-moz-border-radius: 15px;
				border-radius: 15px;
				color: #FFF;
				font-weight: light;
				border: 1px solid #CCC;
				padding: 5px 15px;
				background: rgb(101,175,232);
				background: -moz-linear-gradient(top, rgba(101,175,232,1) 0%, rgba(49,113,193,1) 100%);
				background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(101,175,232,1)), color-stop(100%,rgba(49,113,193,1)));
				background: -webkit-linear-gradient(top, rgba(101,175,232,1) 0%,rgba(49,113,193,1) 100%);
				background: -o-linear-gradient(top, rgba(101,175,232,1) 0%,rgba(49,113,193,1) 100%);
				background: -ms-linear-gradient(top, rgba(101,175,232,1) 0%,rgba(49,113,193,1) 100%);
				background: linear-gradient(top, rgba(101,175,232,1) 0%,rgba(49,113,193,1) 100%);
				filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#65afe8', endColorstr='#3171c1',GradientType=0 );
			}
			
			ok:hover {
				/*border-radius*/
				-webkit-border-radius: 15px;
				-moz-border-radius: 15px;
				border-radius: 15px;
				color: #FFF;
				font-weight: 500;
				-webkit-box-shadow: 0px 0px 5px #CCC;
				-moz-box-shadow: 0px 0px 5px #CCC;
				box-shadow: 0px 0px 5px #CCC;
				padding: 5px 15px;
				position: relative;
				background: rgb(62,158,229);
				background: -moz-linear-gradient(top, rgba(62,158,229,1) 0%, rgba(23,103,202,1) 100%);
				background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(62,158,229,1)), color-stop(100%,rgba(23,103,202,1)));
				background: -webkit-linear-gradient(top, rgba(62,158,229,1) 0%,rgba(23,103,202,1) 100%);
				background: -o-linear-gradient(top, rgba(62,158,229,1) 0%,rgba(23,103,202,1) 100%);
				background: -ms-linear-gradient(top, rgba(62,158,229,1) 0%,rgba(23,103,202,1) 100%);
				background: linear-gradient(top, rgba(62,158,229,1) 0%,rgba(23,103,202,1) 100%);
				filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#3e9ee5', endColorstr='#1767ca',GradientType=0 ); /*box-shadow*/
				-webkit-box-shadow: inset 0 0 3px #666;
				-moz-box-shadow: inset 0 0 3px #666;
				box-shadow: inset 0 0 3px #666;
			}

			ok:active {
				/*border-radius*/
				-webkit-border-radius: 15px;
				-moz-border-radius: 15px;
				border-radius: 15px;
				color: #FFF;
				font-weight: 500;
				border: 2px solid #B3B3B3;
				padding: 5px 15px;
				position: relative;
				background: rgb(77,162,228);
				/*linear-gradient*/
				background: -webkit-gradient(linear,left top,left bottom,color-stop(rgba(77,162,228,1),0),color-stop(rgba(32,85,154,1),1));
				background: -webkit-linear-gradient(top, rgba(77,162,228,1) 0%, rgba(32,85,154,1) 100%);
				background: -moz-linear-gradient(top, rgba(77,162,228,1) 0%, rgba(32,85,154,1) 100%);
				background: -o-linear-gradient(top, rgba(77,162,228,1) 0%, rgba(32,85,154,1) 100%);
				background: linear-gradient(top, rgba(77,162,228,1) 0%, rgba(32,85,154,1) 100%);
				background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(77,162,228,1)), color-stop(100%,rgba(32,85,154,1)));
				background: -webkit-linear-gradient(top, rgba(77,162,228,1) 0%,rgba(32,85,154,1) 100%);
				background: -moz-linear-gradient(top, rgba(77,162,228,1) 0%,rgba(32,85,154,1) 100%);
				background: -o-linear-gradient(top, rgba(77,162,228,1) 0%,rgba(32,85,154,1) 100%);
				background: linear-gradient(top, rgba(77,162,228,1) 0%,rgba(32,85,154,1) 100%);
				filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#4da2e4', endColorstr='#20559a',GradientType=0 );
				/*box-shadow*/
				-webkit-box-shadow: inset 0 0 8px #666;
				-moz-box-shadow: inset 0 0 8px #666;
				box-shadow: inset 0 0 8px #666;
			}
		</style>
	</head>

	<body>
	
		<?php
		function stripAccents($string)
		{
			return strtr($string,'àáâãäçèéêëìíîïñòóôõöùúûüýÿÀÁÂÃÄÇÈÉÊËÌÍÎÏÑÒÓÔÕÖÙÚÛÜÝ', 'aaaaaceeeeiiiinooooouuuuyyAAAAACEEEEIIIINOOOOOUUUUY');
		}
		mysql_connect("localhost", "root");
		mysql_select_db("pme");
		
		if(isset($_GET['r']))
		{
			$r = $_GET['r'];
			$aaa = '<a href="index.php"><< Retour à la liste des clients</a>'; 
			$req = mysql_query("SELECT * FROM client WHERE identifiant='".$r."' OR adresse='".$r."' OR complement='".$r."'
			OR ville='".$r."' OR codePostal='".$r."' OR typeImmeuble='".$r."' OR nombreEtages='".$r."'");
		}
		else
		{		
			$aaa = 'Liste des clients';
			$req = mysql_query("SELECT * FROM client");
		}
		?>
		
		<h2><?php echo $aaa; ?><br /><br />
		<div class="dark">
			<form method="get" action="index.php">
				<span><input name="r" type="text" class="search rounded" placeholder="Recherche..."></span>
				<input type="submit" id="ok" value="Rechercher">
			</form>
		</div>
		</h2>
		<table class="bordered">
			<thead>

			<tr>
				<th>Identifiant</th>        
				<th>Adresse</th>
				<th>Complément d'adresse</th>
				<th>Ville</th>
				<th>Code postal</th>
				<th>Type</th>
				<th>Etages</th>
				<th>Géolocalisation</th>
			</tr>
			</thead>
			
			<?php
				while($i = mysql_fetch_array($req))
				{
					echo '<tr>';
					for ($a=0; $a<7; $a++)
						echo '<td>'.$i[$a].'</td>';
					echo '<td><a href="https://maps.google.fr/maps?q='.stripAccents($i[1]).'+'.$i[3].'+'.$i[4].'&ie=UTF8&oe=utf-8&client=firefox-a&channel=fflb&hnear='.stripAccents($i[1]).'+'.$i[3].'+'.$i[4].'&gl=fr&t=m&z=16">';
					echo '<img src="maps_ico.png" title="Google Maps" alt="Google Maps" width="48" height="48">';
					echo '</a></td>';
					echo '</tr>';
				}
			?>		       

		</table>
		
	</body>
</html>
