<form action="" method="post">
Form ve bang :<align="center"/></br>
So dong :<input type="text" name="sodong" placeholder="so dong" value=""/></br></br>
 So cot :<input type="text" name="socot" placeholder="so cot" value=""/></br></br>

<input type="reset" name="nhaplai" value="nhap lai"/>
<input type="submit" name="ve" value="ve"/>
</form>
<?php
	if($_SERVER["REQUEST_METHOD"]=="POST")
	{
		if(!empty($_POST["sodong"])&&!empty($_POST["socot"]))
		{
			$id=$_POST["sodong"];
			$jc=$_POST["socot"];
			echo"</br>"."so dong "."$id";
			echo"</br>"."so cot "."$jc";
			echo"<table border=1 width=400 height=200>";
				for($i=0;$i<$id;$i++){
				echo"<tr>";
					for($j=0;$j<$jc;$j++){
					echo"<td></td>";
					}
				echo"</tr>";
		}
			echo"</table>";
	}	
		else
		{
			
			echo"</br>"."thong tin chua duoc nhap day du ";
		}
	}
?>