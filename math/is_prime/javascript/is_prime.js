<script>
	function Prime()
	{
		var i,flag=0,number;
		number = Number(document.getElementById("N").value);

		for(i=2; i <= number/2; i++)
		{
			if(number%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			window.alert(number+"-The inputed number is Prime");
		}
		else
		{
			window.alert(number+"-The inputted number is not Prime");
		}
	}
</script>