const URL = "http://localhost:8000";
const tableContainer = document.querySelector(".table-responsive");
const tbody = document.querySelector("tbody");
const logout = document.getElementById("logout");

async function getCustomers() {
  const response = await fetch(`${URL}/customers`);
  if (response.status === 200) {
    return await response.json();
  }
}

async function handleOnLoad() {
  const {data: users} = await getCustomers() 
  console.log('users', users)
  if (users.length > 0) {
    users.forEach((i) => {
      const tBodyRow = tbody.insertRow()
      const tBodyCellId = tBodyRow.insertCell()
      const tBodyCellName = tBodyRow.insertCell()
      const tBodyCellGroup = tBodyRow.insertCell()
      const tBodyCellEstado = tBodyRow.insertCell()
      tBodyCellId.innerText = i.id
      tBodyCellName.innerText = i.nombre
      tBodyCellGroup.innerText = i.groups?.join?.(', ') || 'Orden vacía'
      tBodyCellEstado.innerText = 'Activo'
      if (!i.isLogged) {
        tBodyCellEstado.innerText = 'Inactivo'
      }
    })
    return
  }
}

async function handleOnClickLogout() {
  const customerID = localStorage.getItem("customerID");
  const response = await fetch(`${URL}/logout/${customerID}`, {
    method: "PUT",
    mode: "cors",
    headers: { "Content-Type": "application/json" },
  });
  const data = await response.json();

  if (response.status !== 200) {
    alert(data.error);
    return;
  }

  window.location.href = "/";
}

document.onload = handleOnLoad();
logout.onclick = handleOnClickLogout;