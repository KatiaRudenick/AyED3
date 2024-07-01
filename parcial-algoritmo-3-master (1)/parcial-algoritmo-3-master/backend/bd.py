from sqlalchemy import Column, ForeignKey, create_engine
from sqlalchemy.orm import sessionmaker, relationship
from sqlalchemy.types import Integer, VARCHAR, Boolean, TIMESTAMP
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.exc import SQLAlchemyError
from datetime import datetime

# Configuración del motor de la base de datos
engine = create_engine('sqlite:///BD.db')
Session = sessionmaker(bind=engine)
session = Session()
Base = declarative_base()

# Definición de las tablas
class Customer(Base):
    __tablename__ = 'customers'
    id = Column(Integer, primary_key=True, autoincrement=True)
    name = Column(VARCHAR(50))
    status = Column(Boolean, default=True)
    orders = relationship('Order', back_populates='customer')

class Order(Base):
    __tablename__ = 'orders'
    id = Column(Integer, primary_key=True, autoincrement=True)
    id_customer = Column(Integer, ForeignKey("customers.id"))
    orderName = Column(VARCHAR(256))
    orderDate = Column(TIMESTAMP, default=datetime.utcnow)
    customer = relationship('Customer', back_populates='orders')

# Creación de las tablas
Base.metadata.create_all(engine)

class CustomersManager:
    def add_user(self, name):
        try:
            existing_user = session.query(Customer).filter_by(name=name).first()
            if existing_user:
                existing_user.status = True
                session.commit()
                return {"message": f"Welcome {name}", "customerID": existing_user.id}, 200

            newCustomer = Customer(name=name, status=True)
            session.add(newCustomer)
            session.commit()
            return {"message": f"User '{name}' successfully added", "customerID": newCustomer.id}, 200

        except SQLAlchemyError as e:
            session.rollback()
            return {"error": str(e)}, 500

    def change_status(self, customerID):
        try:
            customer = session.query(Customer).get(customerID)
            if not customer:
                return {"error": f"No customer found with ID {customerID}"}, 406
            
            customer.status = False
            session.commit()
            return {"message": "Status updated"}, 200

        except SQLAlchemyError as e:
            session.rollback()
            return {"error": str(e)}, 500

    def get_customers(self):
        try:
            customers = session.query(Customer).all()
            users = [{"id": c.id, "nombre": c.name, "isLogged": c.status} for c in customers]
            return {"message": "ok", "data": users}, 200

        except SQLAlchemyError as e:
            return {"error": str(e)}, 500

    def add_order(self, customerID, orderName):
        try:
            customer = session.query(Customer).get(customerID)
            if not customer:
                return {"error": f"No customer found with ID {customerID}"}, 406
            
            newOrder = Order(id_customer=customerID, orderName=orderName)
            session.add(newOrder)
            session.commit()
            return {"message": f"Order '{orderName}' successfully added"}, 200

        except SQLAlchemyError as e:
            session.rollback()
            return {"error": str(e)}, 500

    def get_orders(self, customerID):
        try:
            orders = session.query(Order).filter_by(id_customer=customerID).all()
            order_list = [
                {"id": o.id, "orderDate": o.orderDate, "orderName": o.orderName, "customer": o.customer.name}
                for o in orders
            ]
            return {"message": "ok", "data": order_list}, 200

        except SQLAlchemyError as e:
            return {"error": str(e)}, 500